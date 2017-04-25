
#include "TrackerPod.h"

#include "protocolo.h"


CTrackerPod *g_pTrackerPod = NULL;
HWND g_hwnd = NULL;
int g_index = -1;
char g_version[16];
int g_status = 0;
unsigned long g_user_data = 0;


char getKeyPress() {
char KeyPress;
std::cin.get(KeyPress);
return KeyPress;
}


// Variables de incialización de los Windows Sockets


	SOCKET sockfd;
	struct sockaddr_in dst,local_addr,input_in;
	char buff[2048], buffer[1024], cadena[2048];
	int recibidos=0, enviados=0, tam;

	char servidor;
	int salir=0;
	char user_input[1024];
	int n_secuencia=1;
    char ipdest[20]="";
	char iplocal[]="127.0.0.1";
	char HostName[255];
	struct hostent *host_entry;
	char* LocalIP;
	extern float x, y, z;
	char comando[10];
	int input_l;
	int in_len;
	

int conexion()
{
	// Variables de incialización de los Windows Sockets


	wVersionRequested=MAKEWORD(1,1);
	err=WSAStartup(wVersionRequested,&wsaData);
	if(err!=0){
		return(0);
	}
	if(LOBYTE(wsaData.wVersion)!=1||HIBYTE(wsaData.wVersion)!=1)
	{
		WSACleanup();
		return(0);
	}

	//Creación del socket
	sockfd=socket(AF_INET,SOCK_DGRAM,0);

	if(sockfd==INVALID_SOCKET)
	{
		printf("\nERROR AL CREAR SOCKET");

	
	}
	else
	{	//AQUI PONEMOS LOS PRINTF DE LAS OPCIONES QUE QUEREMOS
		printf("\nSOCKET CREADO CORRECTAMENTE\n");
		//printf("\nIntroduce la cadena de caracteres:\n");
		printf(" * direccion IP del servidor y a continuacion el comando 'iniciar' (sin comillas)\r\n\r\n");
		printf(" * Para mover la camara  se utilizan los cursores\r\n\r\n");

		printf(" * Para abandonar la aplicacion escribe QUIT\r\n\r\n");
		printf("---------------------------------------------\r\n\r\n");
	
		//Obtencion de la direccion del propio equipo
		gethostname(HostName, 255);
		host_entry=gethostbyname(HostName);

			//Se configura la estrucctura de la direccion del servidor
		local_addr.sin_family=AF_INET;
		srand(time(0));
        local_addr.sin_port=htons(getrandom(1024,65535));
		local_addr.sin_addr.s_addr=inet_addr(iplocal);
		



		//Se asocia el socket al puerto
 if (bind(sockfd,(struct sockaddr*)&local_addr,sizeof(local_addr))==SOCKET_ERROR){
           
		printf("\r\nError %d: No se ha podido hacer el BIND\r\n",GetLastError());
			
        }

		else
		{
			DWORD mode=0;
			
		//	printf("Bienvenido al Cliente de Eco UDP\r\n");
		//	printf("Infrotuzca una cadena para enviar al servidor: ");
				
			if(ioctlsocket(sockfd,FIONBIO,&mode)==SOCKET_ERROR)
			{
				printf("No se ha podido establecer el modo no bloqueante\r\n");
			
			}
				printf("Introduzca la IP del SERVIDOR: ");

			    gets_s(cadena,sizeof(cadena));
				if(strcmp(cadena,"")!=0)
				strcpy_s(ipdest,sizeof(ipdest),cadena);
				
		}
	}//fin INVALID_SOC

 //Se configura la estructura de direccion del servidor

			dst.sin_family=AF_INET;
			srand(time(0));
			dst.sin_port=htons(UDP_SERVER_PORT);
			dst.sin_addr.s_addr=inet_addr(ipdest);

		

	}

void comunicacion(){
	char mi_id=15;
	printf("\r\nIntroduzca comando para enviar al servidor: ");
	gets_s(user_input,sizeof(user_input));
	if(strcmp(user_input,"iniciar")==0){
		sprintf_s(buffer,sizeof(buffer),"%s %d %d %d %d\r\n",user_input,(short)mi_id,(short)x,(short)y,(short)z);
	}
	enviados=sendto(sockfd,buffer,(int)strlen(buffer),0,(struct sockaddr *)&dst,sizeof(dst));

	do{	
		in_len=sizeof(buffer);
		input_l=sizeof(input_in);

		recibidos=recvfrom(sockfd,buffer,in_len,0,(struct sockaddr*)&input_in,&input_l);

		if(recibidos!=SOCKET_ERROR)
			{

	//g_pTrackerPod = CTrackerPod::CreateTrackerPod();
	//if(!g_pTrackerPod)
		//return 0;
	buffer[recibidos]=0;
			printf("\r\nRecibido de %s %d: %s",inet_ntoa(input_in.sin_addr),ntohs(input_in.sin_port),buffer);

			//Se analiza el comando recibido del servidor
			sscanf_s(buffer,"%s %d %d %d %d %d %d",comando,sizeof(comando));



		

			/*enviados=sendto(sockfd,buffer,(int)strlen(buffer),0,(struct sockaddr*)&dst,sizeof(dst));
			if(enviados!=SOCKET_ERROR){


					printf("Enviados %d\r\n",enviados);
					buffer[enviados]=0x00;
					n_secuencia++;
					in_len=sizeof(buffer);
					input_l=sizeof(input_in);
			
			printf("\r\nCadena recibida correctamente\n");
			recibidos=recvfrom(sockfd,buffer,512,0,(struct sockaddr*)&dst,&tam);

			if(recibidos!=SOCKET_ERROR)
			{
			buffer[recibidos]=0x00;
			printf("%s\n",buffer);
			printf("Introduzca nueva cadena\n");
			}
			}else{
				printf("\r\nerror\n");
			}
     //       }while(strcmp("",user_input)!=0);
	}while(strcmp(cadena,"QUIT")!=0);
		

		}*/
		}
	strcpy(buffer,""); //Se vacia el buffer de envio
	}while(strcmp(cadena,"QUIT")!=0);
}

#define MessageBox
#define ComboBox_ResetContent
#define ComboBox_GetItemData
#define ComboBo_GetCount


void __stdcall devchg_callback(int index, char *ver, int status, unsigned long user_data)
{
	if(g_hwnd)
	{
		g_index = index;
		strcpy(g_version, ver);
		g_status = status;
		g_user_data = user_data;
		PostMessage(g_hwnd, WM_DEV_CHANGE_NOTIFY, 0, NULL);
	}
}

int g_xPos, g_yPos; 
HINSTANCE	g_hInstance = NULL;


BOOL CALLBACK DialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	switch (msg)
	{
	case WM_DEV_CHANGE_NOTIFY:
		{
			char szHello[255];
			sprintf(szHello, "index: %d status: %d ver: %s  user_data: %d", g_index, g_status, g_version, g_user_data);
			//SetWindowText(hwnd, szHello);

			BOOL bEnable = FALSE;
			if(g_status != 0)
				bEnable = TRUE;

			/*EnableWindow(GetDlgItem(hwnd, IDC_BUTTON_LEFT), bEnable);
			EnableWindow(GetDlgItem(hwnd, IDC_BUTTON_RIGHT), bEnable);
			EnableWindow(GetDlgItem(hwnd, IDC_BUTTON_UP), bEnable);
			EnableWindow(GetDlgItem(hwnd, IDC_BUTTON_DOWN), bEnable);
			EnableWindow(GetDlgItem(hwnd, IDC_BUTTON_HOME), bEnable);

			EnableWindow(GetDlgItem(hwnd, IDC_BUTTON_GET_POS), bEnable);
			EnableWindow(GetDlgItem(hwnd, IDC_STATIC_POS), bEnable);

			EnableWindow(GetDlgItem(hwnd, IDC_COMBO_CONTROL), bEnable);*/
			break;
		}

	case WM_COMMAND:

		if(LOWORD (wParam) == IDC_BUTTON_MOVE_EXT)
		{
			wchar_t move_ext_cmd[1024];
			GetDlgItemText(hwnd, IDC_EDIT_MOVE_EXT, move_ext_cmd, sizeof(move_ext_cmd) - 1);
			if(move_ext_cmd[0] == '\0')
			{
				MessageBox(hwnd, "Please type in valid string", "wintpod", MB_OK);
				break;
			}
			g_pTrackerPod->control(move_ext_cmd);

		}



		if(LOWORD (wParam) == IDC_BUTTON_INITIALIZE)
		{
			char client_id[100];
			GetDlgItemText(hwnd, IDC_EDIT_CLIENT_ID, client_id, sizeof(client_id) - 1);

			if(client_id[0] == '\0')
			{
				MessageBox(hwnd, "Please type in client ID", "wintpod", MB_OK);
				break;
			}
 
			if(g_pTrackerPod->initialize(client_id, devchg_callback))
			{
				HWND but_init = GetDlgItem(hwnd, IDC_BUTTON_INITIALIZE);
				HWND edt_clid = GetDlgItem(hwnd, IDC_EDIT_CLIENT_ID);
			
			}
			else
				MessageBox(hwnd, "Failed to initialize!", "wintpod", MB_OK);
			break;
		}



	

		if(LOWORD (wParam) == IDC_BUTTON_LEFT)
		{
			g_pTrackerPod->move_by(+1.0, 0.0);
			break;
		}

		if(LOWORD (wParam) == IDC_BUTTON_RIGHT)
		{
			g_pTrackerPod->move_by(-1.0, 0.0);
			break;
		}


		if(LOWORD (wParam) == IDC_BUTTON_UP)
		{
			g_pTrackerPod->move_by(0.0, -1.0);
			break;
		}

		if(LOWORD (wParam) == IDC_BUTTON_DOWN)
		{
			g_pTrackerPod->move_by(0.0, 1.0);
			break;
		}

		if(LOWORD (wParam) == IDC_BUTTON_HOME)
		{
			g_pTrackerPod->move_to(0.0, 0.0);
			break;
		}

	/*	if(LOWORD (wParam) == IDC_BUTTON_GETDEVLIST)
		{
			HWND hwnd_devlist = GetDlgItem(hwnd, IDC_COMBO_DEVPATH_LIST);
			int count = ComboBox_GetCount(hwnd_devlist);
			for(int i = 0; i < count; ++i)
			{
				char *pData = (char *)ComboBox_GetItemData(hwnd_devlist, i);
				delete pData;
			}

			ComboBox_ResetContent(hwnd_devlist);

			int index = ComboBox_AddString(hwnd_devlist, "do not use trackerpod");
			ComboBox_SetItemData(hwnd_devlist, index, NULL);

			if(g_pTrackerPod->begin_enum_device())
			{
				while(true)
				{
					int devid = g_pTrackerPod->enum_next(0);
					if(devid < 0)
						break;

					char devname[256];
					sprintf(devname, "Plug_%d", devid);
					index = ComboBox_AddString(hwnd_devlist, devname);

					int *pData = new int;
					*pData = devid;
					ComboBox_SetItemData(hwnd_devlist, index, pData);
				}
			}
			ComboBox_SetCurSel(hwnd_devlist, 0);
			break;
		}

		if(LOWORD (wParam) == IDC_SHOW_MANAGER)
		{
			if(g_pTrackerPod->is_manager_visible())
				g_pTrackerPod->show_manager(false);
			else
				g_pTrackerPod->show_manager(true);
		}	

		if(HIWORD (wParam) == CBN_SELCHANGE)
		{
			if(GetDlgCtrlID((HWND)lParam) == IDC_COMBO_DEVPATH_LIST)
			{
				DWORD cursel = ComboBox_GetCurSel((HWND)lParam);
				int *devid = (int *)ComboBox_GetItemData((HWND)lParam, cursel);
				if(devid)
					g_pTrackerPod->use_device(*devid);
				else
					g_pTrackerPod->use_device(-1);
			}

	
			break;
		}

		return TRUE;
		*/
	
	/*case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_SIZE:
		return TRUE;*/
	case WM_CLOSE:
		{
			HWND hwnd_devlist = GetDlgItem(hwnd, IDC_COMBO_DEVPATH_LIST);
			int count = ComboBo_GetCount(hwnd_devlist);
			for(int i = 0; i < count; ++i)
			{
			char *pData = (char *)ComboBox_GetItemData(hwnd_devlist, i);
				delete pData;
			}
			ComboBox_ResetContent(hwnd_devlist);
			EndDialog(hwnd, TRUE);
		}

	case WM_LBUTTONDOWN:
		{	

			g_xPos = GET_X_LPARAM(lParam); 
			g_yPos = GET_Y_LPARAM(lParam); 
			SetCapture(hwnd);
			break;
		}

	case WM_LBUTTONUP:
		{
			ReleaseCapture();
			break;
		}
	case WM_MOUSEMOVE:
		{
			if(wParam == MK_LBUTTON)
			{
				int xPos = GET_X_LPARAM(lParam); 
				int yPos = GET_Y_LPARAM(lParam);
				int dx = xPos - g_xPos;
				int dy = yPos - g_yPos;
				g_pTrackerPod->move_by(-dx /2.0, dy/2.0);
				g_xPos = xPos;
				g_yPos = yPos;
			}

			break;
		}
	}
	return FALSE;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.

	g_pTrackerPod = CTrackerPod::CreateTrackerPod();
	if(!g_pTrackerPod)
		return 0;

	g_hInstance = hInstance;
	DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_TRACKERPOD_TEST), NULL, (DLGPROC)DialogProc);

	if(g_pTrackerPod)
		g_pTrackerPod->ReleaseTrackerPod();
	g_pTrackerPod = NULL;

	return 0;
}






