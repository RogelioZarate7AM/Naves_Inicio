#ifndef __NAVE_H__
#define __NAVE_H__
#include "Sprite.h"

class Nave
{
	Sprite * sprite;
	int x;
	int y;
	bool autoMovimiento;

public:
	void Mover(int posicion);
	void Mover2(int posicion);
	Nave(SDL_Surface * screen,char * rutaImagen,int x,int y);//constructor
	void SetAutoMovimiento(bool autoMovimiento);
	void Pintar();
	void Actualizar();
}


#endif
;