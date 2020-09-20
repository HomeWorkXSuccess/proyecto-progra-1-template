#include <graphics.h> 
#include "cuad.h"

Graficos::Graficos() {
}
void Graficos::inicializar() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
}
void Graficos::cerrar() {
	closegraph();
}

void Conway::Iniciar(int x,int y){
	setfillstyle(SOLID_FILL,WHITE);
	outtextxy(520,100,"Jugar");
	bar(x,y,x+100,y+50);
	if(mousex()>x&&mousex()<x+100&&mousey()>y&&mousey()<y+50&&ismouseclick(WM_LBUTTONDOWN)){
	}
}

void Conway::mastiempo(int x2,int y2){
	setfillstyle(SOLID_FILL,CYAN);
	outtextxy(520,200,"mas tiempo");
	bar(x2,y2,x2+100,y2+50);
	if(mousex()>x2&&mousex()<x2+100&&mousey()>y2&&mousey()<y2+50&&ismouseclick(WM_LBUTTONDOWN)){
		int cont;
		delay(100);
		delay(100+50);
	}
}

void Conway::menostiempo(int x2,int y2){
	setfillstyle(SOLID_FILL,12);
	outtextxy(520,300,"menos tiempo");
	bar(x2,y2,x2+100,y2+50);
	if(mousex()>x2&&mousex()<x2+100&&mousey()>y2&&mousey()<y2+50&&ismouseclick(WM_LBUTTONDOWN)){
		int cont;
		delay(100);
		cont-50;
	}
}

//void Conway::salir(){
//	int salir[4];
//	salir[0]=cantcol*tamCeldas+10;
//	salir[1]=10;
//	salir[2]=salir[0]+100;
//	salir[3]=salir[1]+50;
//	pintarbotones(salir[0],salir[1],salir[2],salir[3],"Salir");
//}

void Conway::pintarbotones(int x1, int y1,int x2, int y2, string texto){
	char texto2[50];
	strcpy(texto2, texto.c_str());
	rectangle(x1,y1,x2,y2);
	floodfill(x1+1,y1+1,LIGHTGREEN);
	setcolor(WHITE);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR,1);
	outtextxy(x1+5,y1+5,texto2);
}

Cuadricula::Cuadricula(){	
}
void Cuadricula::dibujarCuadricula(){
	for(int i=0;i<=fil;i++){
		setfillstyle(LINE_FILL,4);
		line(0,i*tamCeldas,col*tamCeldas,i*tamCeldas);
	}
	for(int i=0;i<=col;i++){
		setfillstyle(LINE_FILL,4);
		line(i*tamCeldas,0,i*tamCeldas,fil*tamCeldas);
	}
}

void Cuadricula::getMouseClic() { //devuelve el numero de fila donde hay clic, -1 si no hubo clic
	int x;
	int y;
	getmouseclick(WM_LBUTTONDOWN,x,y);//revisa el boton izquierdo, si es surdo 
									  //y tiene los botones invertidos use
									  //WM_RBUTTONDOWN
	if (x >= 1 && x <= 50*tamCeldas && y >=1 && y <= 50*tamCeldas) {
		//si el clic fue dado dentro de la cuadricula
		posCol = x / tamCeldas;//pone en posCol la columna donde se dio clic
		posFil = y / tamCeldas;//pone en posFil la fila donde se dio clic
	} else {
		posCol =x;
		posFil=y;
	}
}
int Cuadricula::getMouseX() {
	return posCol;
}
int Cuadricula::getMouseY() {
	return posFil;
}

Celda::Celda(){
}
void Celda::setValores(int f, int c, int t) {
	col = c;
	fil = f;
	tipo = t;
}
void Celda::cambiarTipo(int t) {
	tipo = t;//establece un nuevo tipo de celda
}
int Celda::getTipo() {
	return tipo;
}

void Celda::pintarse() {
	if(tipo==0)setfillstyle(SOLID_FILL,WHITE);
	
		bar(col*tamCeldas+1,fil*tamCeldas+1,(col*tamCeldas)+tamCeldas-1,(fil*tamCeldas)+tamCeldas-1);
	
	if (tipo==1){setfillstyle(SOLID_FILL,BLACK);
	
		bar(col*tamCeldas+1,fil*tamCeldas+1,(col*tamCeldas)+tamCeldas-1,(fil*tamCeldas)+tamCeldas-1);
	}
	else if(tipo==2){setfillstyle(SOLID_FILL,GREEN);
	
		bar(col*tamCeldas+1,fil*tamCeldas+1,(col*tamCeldas)+tamCeldas-1,(fil*tamCeldas)+tamCeldas-1);
	}
	else if(tipo==3){setfillstyle(SOLID_FILL,MAGENTA);
	
		bar(col*tamCeldas+1,fil*tamCeldas+1,(col*tamCeldas)+tamCeldas-1,(fil*tamCeldas)+tamCeldas-1);
		}
}


Conway::Conway(){
	int **cd;
	
	cout<<"La cantidad maxima es de 50x50"<<endl;
	cout<<"Por favor ingrese la cantidad de filas que desea: ";
	cin>>fil;
	cout<<"Por favor ingrese la cantidad de columnas que desea: ";
	cin>>col;
	
	if(fil<=50&&col<=50){
		cd=new int* [col];
		for(int i=1;i<fil;i++){
			for(int j=1;j<col;j++){
				cd[i][j];
			}
		}
		
			for(int i=1;i<fil;i++){
			for(int j=1;j<col;j++){
			}
		}
		
			for(int i=1;i<fil;i++){
			for(int j=1;j<col;j++){
				int x=0;
				dt[i][j].setValores(i,j,x);
				dt[i][j].pintarse();
			}
		}
	}
	else{
		cout<<"Invalido! Ha superado el limite de 50x50\n";
	}
}

void Conway::jugar() {
	getMouseClic();
	if (posCol!=0&&posCol<=51) {
		int t = dt[posFil][posCol].getTipo();
		t++;
		if (t > 3)
			t = 0;
		dt[posFil][posCol].cambiarTipo(t);
		dt[posFil][posCol].pintarse();
	}
}

void Conway::Reglas(){
	int cont,contfil,contcol;
	int **dt;
	for(int i=1;i<contfil;i++){
		for(int j=1;j<contcol;j++){
			cont=0;
			if(i!=0){
				if(dt[i-1][j]==1){
					cont++;
				}
			}
			else if(i!=contfil-1){
				if(dt[i+1][j]==1){
					cont++;
				}
			}
			else if(j!=0){
				if(dt[i][j-1]==1){
					cont++;
				}
			}
			else if(j!=contfil-1){
				if(dt[i][j+1]==1){
					cont++;
				}
			}
			else if(i!=0&&j!=0){
				if(dt[i-1][j-1]==1){
					cont++;
				}
			}
			else if(i!=0&&j!=contcol-1){
				if(dt[i-1][j+1]==1){
					cont++;
				}
			}
			else if(i!=contfil-1&&j!=0){
				if(dt[i+1][j-1]==1){
					cont++;
				}
			}
			else if(i!=contfil-1&&j!=contcol-1){
				if(dt[i+1][j+1]){
				}
			}
			else if(dt[i][j]==1&&(cont<2||cont>3)){//si tiene 2 o 3 muertas muere
				dt[i][j]=0;
			}
			else if(dt[i][j]==0&&cont==3){//si tiene 3 vecinas vivas nace
				dt[i][j]=1;
			}
		}
	}
}
