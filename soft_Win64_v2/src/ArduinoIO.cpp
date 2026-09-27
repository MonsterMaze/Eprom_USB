/**
 * 
 * Eprom Programmer
 * 
 * Copyright (C) 2021-2023 Ciprian Stingu
 * ciprian stingu at gmail dot com
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111 USA
 * or see <http://www.gnu.org/licenses/>
 * 
 */
//----------------------------------------------------------------------
#include "ArduinoIO.h"
#include <QDebug>
#include <locale.h>
#include <string>
//----------------------------------------------------------------------

ArduinoIO::ArduinoIO(QSerialPort *port)
{
    serialPort = port;
    m_estadoActual = Idle;
    m_incomingBuffer.clear();

    ResetVariables();

    // CONEXIÓN DEFINITIVA DE RAÍZ:
    // El puerto le avisa de forma reactiva a onReadyRead cada vez que entran bytes
    connect(serialPort, &QSerialPort::readyRead, this, &ArduinoIO::onReadyRead);
}
//----------------------------------------------------------------------

ArduinoIO::~ArduinoIO()
{

}
//----------------------------------------------------------------------

void ArduinoIO::ResetVariables(void)
{
    selectedEpromType = EPROM_TYPE::NONE;
    maxBufferSize = 0;
    readBuffer.clear();
    writeBuffer.clear();
    programmingAlghoritm = PRG_ALGO::STANDARD;
}
//----------------------------------------------------------------------

int ArduinoIO::GetEpromSize(void)
{
    return maxBufferSize;
}
//----------------------------------------------------------------------

QByteArray *ArduinoIO::GetReadBuffer(void)
{
    return &readBuffer;
}
//----------------------------------------------------------------------

QByteArray *ArduinoIO::GetWriteBuffer(void)
{
    return &writeBuffer;
}
//----------------------------------------------------------------------

void ArduinoIO::Send(const QByteArray &data)
{
    emit SerialOperationStartSignal();
    serialPort->write(data);
    serialPort->flush(); // Fuerza la salida física en Windows
}

//======================================================================
// RECEPTOR ASINCRÓNICO INTELIGENTE
//======================================================================
void ArduinoIO::onReadyRead(void)
{
    // 1. Si estamos leyendo la EPROM, capturamos los bytes puros de la memoria
    if (m_estadoActual == LeyendoEprom) {
        QByteArray rafagaData = serialPort->readAll();

        if (!rafagaData.isEmpty()) {

            // === FILTRO DE CABECERA INITIAL ===
            // Si el buffer está vacío y lo que llega contiene las respuestas del protocolo,
            // limpiamos la cabecera antes de guardar los bytes reales de la memoria.
            if (readBuffer.isEmpty()) {
                QString cabeceraCompleta = QString(RESPONSE_READ_EPROM) + "\r\n";
                int indexRead = rafagaData.indexOf(cabeceraCompleta.toUtf8());

                if (indexRead != -1) {
                    // Cortamos todo lo que esté antes del final de "@RSPREAD\r\n"
                    rafagaData.remove(0, indexRead + cabeceraCompleta.length());
                } else if (rafagaData.contains(RESPONSE_OK)) {
                    // Si solo vino el OK en este paquete, salimos y esperamos el próximo con los datos
                    return;
                }
            }
            // ==================================

            // Si después de limpiar quedó información útil (los bytes reales de la EPROM)
            if (!rafagaData.isEmpty()) {
                readBuffer.append(rafagaData);

                // Movemos la barra con el progreso real
                emit ReadBlockSignal(readBuffer.length());

                // Mandamos a la interfaz gráfica el bloque limpio
                emit ReadEpromDataSignal(readBuffer.length() - rafagaData.length(), rafagaData.length(), reinterpret_cast<uint8_t *>(readBuffer.data()));

                // Si completamos la lectura de la capacidad total del chip, cerramos
                if (readBuffer.length() >= maxBufferSize) {
                    readBuffer.resize(maxBufferSize);
                    m_estadoActual = Idle;
                    emit ReadCompleteSignal();
                    emit SerialOperationCompleteSignal();
                }
            }
        }
        return;
    }

    // 2. Para todos los demás estados (Voltajes, Grabación, Test), por líneas con "\r\n"
    m_incomingBuffer.append(serialPort->readAll());

    while (m_incomingBuffer.contains("\r\n"))
    {
        int index = m_incomingBuffer.indexOf("\r\n");
        QByteArray linea = m_incomingBuffer.left(index);
        m_incomingBuffer.remove(0, index + 2);

        if (!linea.isEmpty()) {
            procesarLineaRecibida(linea);
        }
    }
}


//======================================================================
// PROCESADOR INDEPENDIENTE DE RESPUESTAS
//======================================================================
void ArduinoIO::procesarLineaRecibida(const QByteArray &linea)
{
    // === DEBUG FILTRADO INTELIGENTE ===
    // Solo imprimimos en consola si la línea arranca con "@" (comandos/errores/voltajes).
    // Si arranca con otra cosa (datos puros de la EPROM), no lo mostramos para no saturar.
    if (linea.startsWith('@')) {
        qDebug() << "Línea recibida desde el Nano:" << linea;
    } else if (m_estadoActual == LeyendoEprom) {
        // Opcional: Podés imprimir un mensaje cortito por cada bloque binario que entra
        // qDebug() << ">>> Entró bloque de datos EPROM:" << linea.length() << "bytes.";
    }
    // ==================================

    // Control de Errores Global: Si el Arduino manda un @RSPERR, abortamos de inmediato
    if (linea.startsWith(RESPONSE_ERROR)) {
        QString errorMsg = CleanErrorMessage(linea);
        emit SerialOperationErrorSignal(errorMsg.toStdString().c_str());
        if (m_estadoActual == GrabandoEprom) {
            emit WriteCompleteSignal(false, errorMsg.toStdString().c_str());
        }
        m_estadoActual = Idle;
        emit SerialOperationCompleteSignal();
        return;
    }

    // Filtramos las acciones según el estado en el que esté la PC
    switch (m_estadoActual)
    {
        case LeyendoVoltajes:
        {
            if (linea.startsWith(RESPONSE_OK)) return; // Ignoramos el OK inicial

            if (linea.startsWith(RESPONSE_VOLTAGE_INFO))
            {
                // Extraemos la información del voltaje
                QByteArray datosVoltaje = linea;
                datosVoltaje.remove(0, strlen(RESPONSE_VOLTAGE_INFO));

                QStringList voltageList = QString(datosVoltaje).split(QLatin1Char('|'));
                if (voltageList.size() == 2)
                {
                    QString vccVoltage = voltageList[0].replace(QLatin1String("[VCC] "), QLatin1String(""), Qt::CaseSensitive);
                    QString vppVoltage = voltageList[1].replace(QLatin1String("[VPP] "), QLatin1String(""), Qt::CaseSensitive);
                    emit VoltageUpdatedSignal(vccVoltage.simplified().toDouble(), vppVoltage.simplified().toDouble());
                }
                else {
                    emit SerialOperationErrorSignal("Invalid data received!");
                }
                m_estadoActual = Idle;
                emit SerialOperationCompleteSignal();
            }
            break;
        }

        case LeyendoEprom:
        {
            break;
        }

        case GrabandoEprom:
        {
            // Si el Arduino nos confirma que el último bloque se grabó con éxito con un OK
            // y nosotros ya enviamos todos los bytes del archivo, cerramos la operación.
            if (linea.startsWith(RESPONSE_OK)) {
                if (m_bloqueGrabacionActual >= maxBufferSize) {
                    emit WriteBlockSignal(maxBufferSize);
                    emit WriteCompleteSignal(true, nullptr);
                    m_estadoActual = Idle;
                    emit SerialOperationCompleteSignal();
                }
                return;
            }

            if (linea.startsWith(RESPONSE_WRITE_EPROM)) return;

            if (linea.startsWith(RESPONSE_WRITE_BLOCK))
            {
                // El Arduino pide un bloque (Ej: "@RSPBLCK2016")
                int blockIndex = linea.mid(strlen(RESPONSE_WRITE_BLOCK)).simplified().toInt();

                if (m_bloqueGrabacionActual != blockIndex) {
                    emit WriteCompleteSignal(false, "Bloque desincronizado!");
                    m_estadoActual = Idle;
                    emit SerialOperationCompleteSignal();
                    return;
                }

                // Preparamos los bytes a enviar
                char dataToSend[BLOCK_SIZE];
                int bytesRestantes = writeBuffer.length() - m_bloqueGrabacionActual;

                // Si ya no quedan bytes reales por transmitir en el búfer, no enviamos nada
                if (bytesRestantes <= 0) {
                    return;
                }

                int bytesA_Enviar = (bytesRestantes > BLOCK_SIZE) ? BLOCK_SIZE : bytesRestantes;

                memset(dataToSend, 0xFF, BLOCK_SIZE); // Rellenamos con 0xFF por seguridad
                memcpy(dataToSend, &writeBuffer.data()[m_bloqueGrabacionActual], bytesA_Enviar);

                // Transmitimos e incrementamos el puntero
                serialPort->write(dataToSend, BLOCK_SIZE);
                serialPort->flush();

                emit WriteBlockSignal(m_bloqueGrabacionActual);
                m_bloqueGrabacionActual += BLOCK_SIZE;
            }
            break;
        }

    case TesteandoHw:
    {
        // 1. FILTRADO: Ignoramos los comandos de control iniciales del protocolo
        // para que no ensucien la pantalla con textos que antes no estaban.
        if (linea.startsWith(RESPONSE_OK) ||
            linea.startsWith("@RSPTEST ON") ||
            linea.startsWith("@RSPTEST OFF"))
        {
            // Si el Arduino manda el OFF, significa que el test terminó físicamente
            if (linea.startsWith("@RSPTEST OFF")) {
                emit HardwareTestStepSignal(HW_TEST_END); // Agregamos el texto de fin clásico
                m_estadoActual = Idle;
                emit SerialOperationCompleteSignal();
            }
            return;
        }

        // 2. FORMATEO: Le pegamos el salto de línea para que no salga todo amontonado
        QByteArray lineaConSalto = linea + "\n";
        emit HardwareTestStepSignal(lineaConSalto.data());

        // 3. CIERRE ALTERNATIVO: Por si tu Arduino manda la frase literal en el texto
        if (linea.contains("Hardware test end") || linea.contains("end")) {
            m_estadoActual = Idle;
            emit SerialOperationCompleteSignal();
        }
        break;
    }


        default:
            // Si llega un RESPONSE_OK suelto en estado Idle (como al configurar EPROM), cerramos operacion
            if (linea.startsWith(RESPONSE_OK)) {
                emit SerialOperationCompleteSignal();
            }
            break;
    }
}

//======================================================================
// MÉTODOS DISPARADORES DE COMANDOS PÚBLICOS
//======================================================================

void ArduinoIO::SelectEprom(EPROM_TYPE type)
{
    ResetVariables();
    extern EPROM EpromsList[];

    selectedEpromType = type;
    maxBufferSize = EpromsList[type].MemorySize;
    m_estadoActual = Idle;

    // === CONTROL DE TAMAÑO ===
    qDebug() << "===========================================";
    qDebug() << "CHIP SELECCIONADO ID:" << type;
    qDebug() << "Tamaño asignado en maxBufferSize:" << maxBufferSize << "bytes";
    qDebug() << "===========================================";

    char command[1024];
    sprintf(command, COMMAND_SET_EPROM_TYPE, EpromsList[type].EpromType);
    Send(command);
}

void ArduinoIO::ReadVoltage(void)
{
    m_estadoActual = LeyendoVoltajes;
    Send(COMMAND_VOLTAGE_INFO);
}

void ArduinoIO::ReadEprom(void)
{
    qDebug() << ">>> Iniciando LECTURA. maxBufferSize actual:" << maxBufferSize;
    readBuffer.clear();
    m_estadoActual = LeyendoEprom;
    Send(COMMAND_READ_EPROM);
}

void ArduinoIO::HardwareTest(void)
{
    m_estadoActual = TesteandoHw;
    Send(COMMAND_HW_TEST);
}

void ArduinoIO::WriteEprom(double vcc, double vpp, PRG_ALGO algo)
{
    qDebug() << ">>> Iniciando GRABACIÓN. maxBufferSize actual:" << maxBufferSize;
    m_estadoActual = GrabandoEprom;
    m_bloqueGrabacionActual = 0;
    programmingAlghoritm = algo;

    char command[1024]; // <--- CORREGIDO AQUÍ
    sprintf(command, COMMAND_WRITE_EPROM, vcc, vpp, algo);
    Send(command);
}

//======================================================================
// MANTENEMOS LOS SLOTS VIEJOS VACÍOS PARA NO ROMPER LA COMPILACIÓN
//======================================================================
void ArduinoIO::SelectEpromSlot(void) {}
void ArduinoIO::ReadVoltageSlot(void) {}
void ArduinoIO::ReadEpromSlot(void) {}
void ArduinoIO::HarwareTestSlot(void) {}
void ArduinoIO::WriteEpromSlot(void) {}

QString ArduinoIO::CleanErrorMessage(QByteArray errorMessage)
{
    return QString::fromUtf8(errorMessage).replace(RESPONSE_ERROR, "").trimmed();
}
