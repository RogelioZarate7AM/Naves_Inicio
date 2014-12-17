#ifndef __OBJETO_H__
#define __OBJETO_H__
#include "Sprite.h"

class Objeto
{
	Sprite * sprite;
	int x;
	int y;
	int w;
	int h;
	bool autoMovimiento;
	int pasoActual;
	int pasoLimite;
	int module;//Modulo Actual
	bool isVisible;

public:
	void SetVisible(bool isVisible);
	void Mover(int posicion);
	void Mover2(int posicion);
	Objeto(SDL_Surface * screen,char * rutaImagen,int x,int y,int module);//constructor
	void SetAutoMovimiento(bool autoMovimiento);
	void SetPasoLimite(int pasos);
	int ObtenerPasoActual();
	void IncrementarPasoAcutal();
	bool EstaColicionando(Objeto * b);
	void Pintar();
	void Pintar(int module,int x,int y);
	void Actualizar();
	int ObtenerX();
	int ObtenerY();
	int ObtenerW();
	int ObtenerH();
	void PonerEn(int x,int y);
}


#endif
;