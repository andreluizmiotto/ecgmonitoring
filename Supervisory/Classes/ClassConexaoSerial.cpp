// ---------------------------------------------------------------------------
#include "ClassConexaoSerial.h"
#pragma hdrstop
// ---------------------------------------------------------------------------
#pragma package(smart_init)

// ---------------------------------------------------------------------------
SerialPort::SerialPort()
{
	// Variável que que receberá a porta serial aberta.
	hComm = NULL;

	// Valores padrão.
	BaudRate = CBR_115200; // CBR_38400, CBR_9600
	Parity = NOPARITY; // 0 - 4 = no, odd, even, mark, space
	StopBits = ONESTOPBIT; // 0 - 2 = 1, 1.5, 2
	ByteSize = 8;

	// Configuração dos tamanhos dos buffers de leitura e escrita.
	dwToRead = 8096;
}
// ---------------------------------------------------------------------------
SerialPort::~SerialPort()
{

}
// ---------------------------------------------------------------------------

static wchar_t* charToWChar(const char* text)
{
	const size_t size = strlen(text) + 1;
	wchar_t* wText = new wchar_t[size];
	mbstowcs(wText, text, size);
	return wText;
}

BOOL SerialPort::OpenSerialPort(System::AnsiString asPort, System::AnsiString asBaudRate)
{
	System::AnsiString asCommPort;

	// Verifica se há uma porta serial ainda aberta caso exista ela é fechada.
	if (hComm != NULL) {
		// Fecha a porta serial.
		CloseHandle(hComm);
		hComm = NULL;
	}

	// Configuração do nome da porta serial selecionada.
	asCommPort = "\\\\.\\" + asPort;

	// Configurações do Baud Rate da porta serial selecionada.
	if (asBaudRate == "256000")
		BaudRate = CBR_256000;
	if (asBaudRate == "128000")
		BaudRate = CBR_128000;
	if (asBaudRate == "115200")
		BaudRate = CBR_115200;
	if (asBaudRate == "57600")
		BaudRate = CBR_57600;
	if (asBaudRate == "56000")
		BaudRate = CBR_56000;
	if (asBaudRate == "38400")
		BaudRate = CBR_38400;
	if (asBaudRate == "19200")
		BaudRate = CBR_19200;
	if (asBaudRate == "14400")
		BaudRate = CBR_14400;
	if (asBaudRate == "9600")
		BaudRate = CBR_9600;
	if (asBaudRate == "4800")
		BaudRate = CBR_4800;
	if (asBaudRate == "2400")
		BaudRate = CBR_2400;
	if (asBaudRate == "1200")
		BaudRate = CBR_1200;

	// Abertura da porta serial selecionada.
	hComm = CreateFile(charToWChar(asCommPort.c_str()),
							 GENERIC_READ | GENERIC_WRITE,
							 0,      //  must be opened with exclusive-access
							 NULL,   //  default security attributes
							 OPEN_EXISTING, //  must use OPEN_EXISTING
							 0,      //  not overlapped I/O
							 NULL ); //  hTemplate must be NULL for comm devices

	// Verifica se a porta foi aberta corretamente.
	if (hComm == INVALID_HANDLE_VALUE)
	{
		 //  Handle the error.
		 printf ("CreateFile failed with error %lu.\n", GetLastError());
		 return (false);
	}

	//  Inicializa a estrutura DCB.
	DCB dcb;
	SecureZeroMemory(&dcb, sizeof(DCB));
	dcb.DCBlength = sizeof(DCB);

	BOOL fSuccess = GetCommState(hComm, &dcb);

	if (!fSuccess)
	{
		//  Handle the error.
		printf ("GetCommState failed with error %lu.\n", GetLastError());
		return (false);
	}

	//  Fill in some DCB values and set the com state:
	dcb.BaudRate = BaudRate;     //  baud rate
	dcb.ByteSize = ByteSize;     //  data size, xmit and rcv
	dcb.Parity   = Parity;       //  parity bit
	dcb.StopBits = StopBits;     //  stop bit

	fSuccess = SetCommState(hComm, &dcb);

	if (!fSuccess)
	{
		//  Handle the error.
		printf ("SetCommState failed with error %lu.\n", GetLastError());
		return (false);
	}

	//  Get the comm config again.
	fSuccess = GetCommState(hComm, &dcb);

	if (!fSuccess)
	{
		//  Handle the error.
		printf ("GetCommState failed with error %lu.\n", GetLastError());
		return (false);
	}

	return (true);
}

// ---------------------------------------------------------------------------

BOOL SerialPort::WriteABuffer(char *Buffer, DWORD dwToWrite)
{
	OVERLAPPED osWrite = {0};

	if (hComm != NULL) {
		// Create this writes OVERLAPPED structure hEvent.
		osWrite.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

		if (osWrite.hEvent == NULL) {
			return (false); // Error creating overlapped event handle.
		}

		if (!WriteFile(hComm, Buffer, dwToWrite, &dwWritten, &osWrite)) {
			// ShowMessage("ERRO AO ENVIAR DADOS PARA A PORTA SERIAL");
		}

		CloseHandle(osWrite.hEvent);
	}
	else {
		// ShowMessage("ERRO AO ABRIR A PORTA SERIAL");
		CloseHandle(hComm);
		return (FALSE);
	}

	// Finaliza todas as pendências de escrita e leitura da porta serial selecionada.
	PurgeComm(hComm,
		PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);

	return (true);
}

// ---------------------------------------------------------------------------

std::vector<unsigned char> SerialPort::ReadABuffer()
{
	OVERLAPPED osRead = {0};
	std::vector <unsigned char> ABuffer(8096);

	if (hComm == NULL) {
		CloseHandle(hComm);
		return ABuffer;
	}
	// Create this writes OVERLAPPED structure hEvent.
	osRead.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	if (osRead.hEvent == NULL) {
		CloseHandle(hComm);
		return ABuffer;
	}

	if (ReadFile(hComm, &Buffer, dwToRead, &dwRead, &osRead)) {
		//Encerra corretamente a string para não retornar lixo.
		Buffer[dwRead] = '\0';
		memcpy(&ABuffer[0], &Buffer[0], dwRead*sizeof(char));
	}

	CloseHandle(osRead.hEvent);
	//Finaliza todas as pendências de escrita e leitura da porta serial selecionada.
	PurgeComm(hComm, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);

	return (ABuffer);
}

//---------------------------------------------------------------------------

unsigned int SerialPort::getBufferSize()
{
	// Obtém o número de bytes no buffer serial a serem lidos.
	return (dwRead);
}

// ---------------------------------------------------------------------------

void SerialPort::CloseSerialPort()
{
	// Fecha a porta serial aberta.
	if (hComm != NULL) {
		SetCommMask(hComm, 0L);

		CloseHandle(hComm);
		hComm = NULL;
	}
}

// ---------------------------------------------------------------------------

TStringList *SerialPort::LoadComPorts()
{
	TCHAR lpTargetPath[5000]; // Buffer para armazenar o caminho das COMPORTS
	TStringList *AComPorts = new TStringList;
	for(int i = 0; i < 50; i++) // Verifica portas de 0 a 50
	{
		String AComPort = "COM" + IntToStr(i);
		try {
			DWORD ASuccess = QueryDosDevice(AComPort.c_str(), lpTargetPath, 5000);
			if(ASuccess!=0)
				AComPorts->Add(AComPort);

			if(::GetLastError()==ERROR_INSUFFICIENT_BUFFER){ }
		}
		catch (const Exception& e)
		{ }
	}
	return AComPorts;
}
