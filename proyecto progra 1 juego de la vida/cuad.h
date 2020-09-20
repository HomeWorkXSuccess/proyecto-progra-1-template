#include <graphics.h> 
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<iostream>
#include<cstdio>
#include<time.h>
#include<windows.h>

using namespace std;

#define tamCeldas 15

class Graficos {
public:			
	Graficos();
	void inicializar();
	void cerrar();
};
class Cuadricula: public Graficos{
protected:
	int posCol,posFil,fil,col;
public:
	Cuadricula();
	void dibujarCuadricula();
	void getMouseClic();
	int getMouseX();
	int getMouseY();
};

class Celda: public Graficos{
	private:					   
	int tipo;
	int fil,col;
public:
	Celda();
	void setValores(int f, int c, int t);//establece fila, columna y tipo de celda
	void cambiarTipo(int t);//cambia el tipo de celda
	int getTipo();//devuelve el tipo de celda
	void pintarse();
};

class Conway: public Cuadricula{
	protected:
		Celda dt[50][50];

	public:
		Conway();
		void jugar();
		void Reglas();
		void Iniciar(int x,int y);
		void mastiempo(int x2,int y2);
		void menostiempo(int x2,int y2);
		//void salir();
		void pintarbotones(int x1, int y1,int x2, int y2, string texto);
};

