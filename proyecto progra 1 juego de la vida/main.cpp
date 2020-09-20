#include "cuad.h"

main(int argc, char *argv[])
{	
	Graficos G;
	while(true){
	G.inicializar();
	Conway C;
	C.dibujarCuadricula();
	
	do{
		while(!ismouseclick(WM_LBUTTONDOWN)){
		delay(60);
		}
		C.jugar();
		C.Iniciar(500,120);
		C.mastiempo(500,220);
		C.menostiempo(500,320);
		//C.salir();
	}while(!kbhit());
	
	}return 0;
}
