#include "protocolo.h"
	
	void DoCommand(CString strCommand, CString strParam);
	CTrackerPod *g_pTrackerPod = NULL;

		
	SOCKET sockfd;
	struct sockaddr_in local_addr,dst;
	char buffer[2048],cmd[10];
	int recibidos=0;
	int recepcion=0;
	int cont=0;
    int a=1;
    int tama;
	int enviados=0;
	int nCount = 0;
	int input_in;
    int input_l;
	char comando[10];
	int param1, param2, param3, param4;
	int num_clientes=5; //5 clientes inicialmente

	char iplocal[20]="127.0.0.1";

int conexion(){	
	// Inicialización Windows Sockets

    wVersionRequested=MAKEWORD(1,1);
	err=WSAStartup(wVersionRequested,&wsaData);
	if(err!=0)
		return(0);

	if(LOBYTE(wsaData.wVersion)!=1||HIBYTE(wsaData.wVersion)!=1)
	{
		WSACleanup();
		return(0);
	}
	// Fin Inicialización Windows Sockets
/*** Creacion del Socket ******************************************************************************/
	sockfd=socket(PF_INET,SOCK_DGRAM,0);

   if(sockfd==INVALID_SOCKET){
	  
		printf("\r\nERROR AL CREAR SOCKET\r\n");
	  
   }else{
		printf("\r\nSOCKET CREADO CORRECTAMENTE\r\n");

		//Se configura la estructura de direccion del servidor

			dst.sin_family=AF_INET;
			
			dst.sin_port=htons(UDP_SERVER_PORT);
			dst.sin_addr.s_addr=inet_addr(INADDR_ANY);

	


	
		/*Dirección local del cliente


		local_addr.sin_family=PF_INET;
        local_addr.sin_port=htons(UDP_SERVER_PORT);
		//local_addr.sin_addr.s_addr=htonl(INADDR_ANY);
		local_addr.sin_addr.s_addr=inet_addr(iplocal);

		*/


/***  Bind ********************************************************************************/
        if (bind(sockfd,(struct sockaddr*)&dst,sizeof(dst))==SOCKET_ERROR){

			printf("\r\nError %d: No se ha podido hacer el BIND\r\n",GetLastError());
        }else{
			DWORD mode=0;

			printf("Bienvenido al Servidor de Eco UDP\r\n");

			if(ioctlsocket(sockfd,FIONBIO,&mode)==SOCKET_ERROR)
			{
				printf("No se ha podido establecer el modo no bloqueante\r\n");
			
			}


		}
   }
}

void comunicacion(){


	int insertar=0;

	//Inicialmente se crea un array de 10 clientes
	struct cliente_entrante* clientes;
	clientes = (struct cliente_entrante*)calloc(num_clientes,num_clientes*sizeof(struct cliente_entrante));
    printf("\nSocket establecido en el puerto: %i",local_addr.sin_port);

/***  Recived from ***********************************************************************/
	printf("\nEsperando transmision del puerto: %i",dst.sin_port);
	
            do{
			input_l=sizeof(input_in);
			recibidos=recvfrom(sockfd,buffer,2047,0,(struct sockaddr *)&input_in,&input_l);

          
			if(recibidos!=SOCKET_ERROR)
			{
				buffer[recibidos]=0;
			printf("Recibido de %s %d: %s\r\n",inet_ntoa(input_in.sin_addr),ntohs(input_in.sin_port),buffer);

			//Se obtienen los datos recibidos
			sscanf_s(buffer,"%s %d %d %d %d",comando,sizeof(comando),&param1,&param2,&param3,&param4);
			
			if(strcmp(comando,"mover")==0){
				clientes[param1].x=param2;
				clientes[param1].y=param3;
				clientes[param1].z=param4;
				if(abs(clientes[param1].x)){
					sprintf_s(buffer,sizeof(buffer)," %d\r\n",(short)clientes[param1].id);

				}else{
					sprintf_s(buffer,sizeof(buffer),"mover %d %d %d %d\r\n",(short)clientes[param1].id,(short)clientes[param1].x,(short)clientes[param1].y,(short)clientes[param1].z);
				}
			}

            //Procesamiento del texto recibido:
           /* strncpy (cmd,buff,4);
			enviados=sendto(sockfd,buff,(int)strlen(buff),0,(struct sockaddr*)&dst,sizeof(dst));
            if(strcmp(cmd,EC)==0){
                        printf ("\nComando recibido :%s", cmd);
                        sprintf(buff,"OK %s",buff+5);
                        recepcion=1;
                        printf("\nCadena a enviar: %s",buff);	//Check-Point que muestra el texto a enviar
                        }
        }
        printf(")\n");*/
/***  Send to *****************************************************************************/
     //  enviados = sendto(sockfd,buff,strlen(buff)+1,0,(SOCKADDR *) &dst,sizeof(dst));
	//	buff[enviados] = 0x00;

/***  Close *******************************************************************************/
    /*    printf ("\nCERRANDO SOCKET");
		shutdown(sockfd,SD_SEND);
		closesocket(sockfd);



	return 0;
	*/
			}

		strcpy(buffer,""); //Se vacia el buffer de salida

	}while(1);

	free(clientes);
	closesocket(sockfd);
	}

int main (int argc, char **argv) {
	conexion();
	comunicacion();
}