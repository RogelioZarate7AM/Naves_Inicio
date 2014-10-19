#include "Nave.h"
#include "Header.h"

Nave::Nave(SDL_Surface * screen,char * rutaImagen,int x, int y)
{
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	this->x=x;
	this->y=y;
	autoMovimiento=false;
}

void Nave::SetAutoMovimiento(bool autoMovimiento){
	this->autoMovimiento= autoMovimiento;
}

void Nave::Actualizar(){
	if(autoMovimiento){
Mover(1);
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
