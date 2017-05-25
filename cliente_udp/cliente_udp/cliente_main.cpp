#include "protocolo.h"
#include "TrackerPod.h"

float angle=0.0;
float x=0.0f, y=1.75f, z=-5.0f;
float lx=0.0f, ly=0.0f, lz=1.0f;

float x_ant=0.0f, z_ant=0.0f;
float x_temp=0.0f, z_temp=0.0f;


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
	int mi_id=15;


int tiempo;
char s[20];
/*Funcion que modifica la linea de vision*/
void girar(float ang){
	lx=sin(ang);
	lz=cos(ang);
	
}

/*Funcion que permite desplazarse en la linea de vision*/
void avanzar(int sentido) {	
	x_ant = x;
	z_ant = z;

	x_temp = x + sentido*(lx)*0.7;
	z_temp = z + sentido*(lz)*0.7;

	if(abs(x_temp)!=abs(-80) && abs(z_temp)!=abs(-80)){ //Control colision con los bordes del escenario
		x = x_temp;
		z = z_temp;
	}else{
		x = x_ant;
		z = z_ant;
	}
	
	// sprintf_s(buffer,sizeof(buffer),"mover %d %d %d %d\r\n",(short)mi_id,(short)x,(short)y,(short)z);
    sprintf_s(buffer,sizeof(buffer),"mover %d %d\r\n",(short)x,(short)z);
	sendto(sockfd,buffer,(int)strlen(buffer),0,(struct sockaddr *)&dst,sizeof(dst));
}


/*Función para interactuar con los cursores*/
void teclado(char tecla, int x, int y){
	switch(tecla){
		case IDC_BUTTON_UP: //Paso adelante
			avanzar(1);
			break;
		case IDC_BUTTON_DOWN: //Paso atrás
			avanzar(-1);
			break;
		case IDC_BUTTON_LEFT: //Mirar a la izquierda
			angle += 0.07f;
			girar(angle);
			break;
		case IDC_BUTTON_RIGHT: //Mirar a la derecha
			angle -=0.07f;
			girar(angle);
			break;
	}
	
	
}


void teclado2(char tecla, int x, int y){
	switch(tecla){
		case 27:  //Salida del programa al pulsar ESC
			sprintf_s(buffer,sizeof(buffer),"salir %d\r\n",(short)mi_id);
		
			enviados=sendto(sockfd,buffer,(int)strlen(buffer),0,(struct sockaddr *)&dst,sizeof(dst));
			closesocket(sockfd);
			exit(0);
	}
}

void hebra( void* pParams ){
	conexion();
	comunicacion();

}

int main (int argc, char **argv){

	

	srand(time(0));
	x=getrandom(-80,80); //Coordenadas aleatorias de inicio en el escenario
	z=getrandom(-80,80);



    return 0;
}