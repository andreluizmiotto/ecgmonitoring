// ---------------------------------------------------------------------------
#ifndef ClassConexaoSerialH
#define ClassConexaoSerialH
// ---------------------------------------------------------------------------
#include <windows.h>
#include <vector>
#include <sstream>
#include <system.hpp>
#include <Classes.hpp>

// ---------------------------------------------------------------------------
class SerialPort
{
	private:
		//Declaração da porta serial.
		HANDLE hComm;

		//Vetores Auxiliares
		char Buffer[8096];
		char Byte;

		//Variáveis de Controle da Porta Serial.
		DWORD dwToRead;
		DWORD dwRead;
		DWORD dwWritten;
		DWORD BaudRate;
		BYTE Parity;
		BYTE StopBits;
		BYTE ByteSize;

	public:
		// Construtor da classe SerialPort.
		SerialPort();

		// Abertura e fechamento da porta serial.
		BOOL OpenSerialPort(System::AnsiString, System::AnsiString);
		void CloseSerialPort();

		// Escrita e leitura do buffer de dados.
		BOOL WriteABuffer(char *, DWORD);
		char * ReadABuffer();
		std::vector<unsigned char> ReadBuffer();

		// Demais parâmetros de controle da porta serial.
		std::vector<std::string>CheckSerialPort();
		void getSerialStatus();
		unsigned int getBufferSize();
		unsigned char getBufferData();
      TStringList *LoadComPorts();
};
// ---------------------------------------------------------------------------
#endif
