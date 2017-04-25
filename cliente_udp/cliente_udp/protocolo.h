#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "TrackerPod.h"
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


#ifdef UNICODE
#define MessageBox  MessageBoxW
#else
#define MessageBox  MessageBoxA
#endif 
#define MessageBox MessageBox

#define _AFXDLL
#define LPCSTR LPSTR 

#define LPCSTR LPSTR 

// ASCII 
typedef char* LPSTR; 
typedef const char* LPCSTR; 

#ifdef _UNICODE 
typedef wchar_t* LPTSTR; 
typedef const wchar_t* LPCTSTR; 
#else 
typedef char* LPTSTR; 
typedef const char* LPCTSTR; 
#endif 

int WINAPI GetWindowTextA(HWND,LPSTR,int);
int WINAPI GetWindowTextW(HWND,LPWSTR,int);
#ifdef UNICODE
#define GetWindowText GetWindowTextW
#else
#define GetWindowText GetWindowTextA
#endif

#define MSGBOX(x) \
{ \
   std::ostringstream oss; \
   oss << x; \
   MessageBox(oss.str().c_str(), "Msg Title", MB_OK | MB_ICONQUESTION); \
}


#ifdef WIN32
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
#endif



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define getrandom(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min)) //funcion definida para generar numeros aleatorios






#define EC  "ECHO"	// ECHO comando para el reenvio de texto
#define UDP_SERVER_PORT	6000 //puerto utilizado por el servidor
#define UDP_CLIENT_PORT 6001


int conexion();
void comunicacion();

//POSIBLES COMANDOS PARA EL MOVIMIENTO
#define UP 0.0,-1.0
#define DOWN 0.0,1.0
#define RIGHT -1.0,0.0
#define LEFT 1.0,0.0





//{{NO_DEPENDENCIES}}
// Microsoft Developer Studio generated include file.
// Used by resource.rc
//
#define IDD_DIALOG1                     101
#define IDD_TRACKERPOD_TEST             101
#define IDD_DEVICE_AVAILABLE            102
#define IDC_BUTTON_LEFT                 1001
#define IDC_BUTTON_RIGHT                1002
#define IDC_BUTTON_UP                   1003
#define IDC_BUTTON_DOWN                 1004
#define IDC_BUTTON_HOME                 1005
#define IDC_COMBO_DEVPATH_LIST          1006
#define IDC_STATIC_VERSION              1008
#define IDC_BUTTON_VER_PATH             1009
#define IDC_STATIC_DEVPATH              1010
#define IDC_BUTTON_RESET                1011
#define IDC_LIST_DEVLIST                1015
#define IDC_BUTTON_YES                  1016
#define IDC_BUTTON_NO                   1017
#define IDC_BUTTON_GETDEVLIST           1018
#define IDC_BUTTON_GET_POS              1019
#define IDC_STATIC_POS                  1021
#define IDC_EDIT_CLIENT_ID              1022
#define IDC_BUTTON_INITIALIZE           1023
#define IDC_EDIT_MOVE_EXT               1026
#define IDC_BUTTON_MOVE_EXT             1027
#define IDC_COMBO_CONTROL               1028
#define IDC_STATIC_CONTROL              1029
#define IDC_EDIT_ZOOM                   1030
#define IDC_SEND_ZOOM_INC               1031
#define IDC_SEND_ZOOM_DEC               1032
#define IDC_SEND_ZOOM                   1033
#define IDC_EDIT_INFO                   1034
#define IDC_EDIT_ZOOM2                  1035
#define IDC_BUTTON_GETINFO              1036
#define IDC_SEND_ZOOM2                  1037
#define IDC_SEND_ZOOM_INC2              1038
#define IDC_SEND_ZOOM_DEC2              1039
#define IDC_EDIT_ZOOM3                  1040
#define IDC_SEND_ZOOM3                  1041
#define IDC_SHOW_MANAGER                1042

// Next default values for new objects
// 
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS
#define _APS_NEXT_RESOURCE_VALUE        103
#define _APS_NEXT_COMMAND_VALUE         40001
#define _APS_NEXT_CONTROL_VALUE         1043
#define _APS_NEXT_SYMED_VALUE           101
#endif
#endif



