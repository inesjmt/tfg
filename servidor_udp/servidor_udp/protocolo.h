
#define EC  "ECHO"	// ECHO comando para el reenvio de texto
#define UDP_SERVER_PORT	6000 //puerto utilizado por el servidor


// Variables de incialización de los Windows Sockets

#ifdef WIN32
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
#endif





#define EC  "ECHO"	// ECHO comando para el reenvio de texto
#include "TrackerPod.h"
#define WM_POD_SERVICE_NOTIFICATION	WM_APP + 4

#include <atlstr.h>  //Para CString
#define MSGBOX(x) \
{ \
   std::ostringstream oss; \
   oss << x; \
   MessageBox(oss.str().c_str(), "Msg Title", MB_OK | MB_ICONQUESTION); \
}
#pragma comment( lib, "wsock32.lib" )
#pragma comment( lib, "ws2_32.lib")
	#include <stdio.h>
#include <string.h>
#include <conio.h>

#include <time.h>
#include <iostream>
#include <objbase.h>

#include <winsock.h>
#include <windows.h >
#define WM_DEV_CHANGE_NOTIFY WM_USER + 0x100
#define ComboBox

//#include <winsock.h>
#include <Winsock2.h>

#define EC  "ECHO"	// ECHO comando para el reenvio de texto
#pragma comment( lib, "wsock32.lib" )
#pragma comment( lib, "ws2_32.lib")



#include <math.h>
#define getrandom(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min)) //funcion definida para generar numeros aleatorios

	//Estructura donde se alamcenan los datos de un cliente
struct cliente_entrante{
	int id;
	struct sockaddr_in dir;
	float x, y, z;

};

int conexion();

void comunicacion();

