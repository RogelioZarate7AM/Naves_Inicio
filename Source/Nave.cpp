#include "Nave.h"
#include <SDL.h>
#include "Objeto.h"

Nave::Nave(SDL_Surface * screen,char * rutaImagen,int x,int y,int module)
{
	nave = new Objeto(screen,rutaImagen,x,y,module);
}

void Nave::Pintar()
{
	nave -> Pintar();
}

void Nave::MoverAbajo()
{
	nave->Mover2(8);
}

void Nave::MoverArriba()
{
	nave->Mover2(-8);
}

void Nave::MoverDerecha()
{
	nave->Mover(8);
}

void Nave::MoverIzquierda()
{
	nave->Mover(-8);
}

Objeto* Nave::GetNaveObjeto()
{
	return nave;
}