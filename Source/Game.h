#pragma once//proteccion
#include <SDL.h>
#include "Objeto.h"
#include "Nave.h"
class CGame
{
public:
	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZANDO
	};

	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();

private:
	
	
	void Menu();
	void Iniciando();
	void MoverEnemigo();
	bool EsLimitePantalla(Objeto * objeto,int bandera);

	int opcionSeleccionada;
	Uint8 * keys;//Esta variable nos servira para ver si determinadas teclas estan o no pulsadas
	SDL_Event event;// La variable event de tipo evento de SDL nos servira para monitorizar el teclado

	SDL_Surface *screen;
	Nave *nave;
	/*Objeto* enemigo;*/
	Objeto *enemigoArreglo[10];

	Objeto *menu;// Fondo del Menu
	Objeto *textos;//Textos del menu
	Objeto *fondo;//Fondo del juego



	int tick;
	int tiempoFrameInicial;
	int tiempoFrameFinal;

	Estado estado;
};