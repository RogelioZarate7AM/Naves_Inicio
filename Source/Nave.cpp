#include "Nave.h"
#include "Header.h"

Nave::Nave(SDL_Surface * screen,char * rutaImagen,int x, int y)
{
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	w = sprite->WidthModule(0);
	h = sprite->HeightModule(0);
	this->x=x;
	this->y=y;
	autoMovimiento=false;
	pasoActual=0;
	pasoLimite=-1;
}

void Nave::SetAutoMovimiento(bool autoMovimiento){
	this->autoMovimiento= autoMovimiento;
}

void Nave::Actualizar(){
	if(autoMovimiento)
	{
Mover(1);
	}
if(pasoLimite>0)
{
	//pasoActual++;
if(pasoActual>=pasoLimite)
	pasoActual = 0;
	}
}

void Nave:: Pintar()
{
	sprite->PintarModulo(0,x,y);
}

void Nave::Mover(int posicion){
	x+=posicion;
}
void Nave::Mover2(int posicion){
	y+=posicion;
}

int Nave::ObtenerX()
{
	return x;
}

int Nave::ObtenerY()
{
	return y;
}

int Nave::ObtenerW()
{
	return w;
}

int Nave::ObtenerH()
{
	return h;
}

void Nave::SetPasoLimite(int pasos)
{
	this->pasoLimite=pasos;
}

int Nave::ObtenerPasoActual()
{
	return pasoActual;
}

void Nave::IncrementarPasoAcutal()
{
	pasoActual++;
}

bool Nave::EstaColicionando(Nave * b)
{
	return false;
}