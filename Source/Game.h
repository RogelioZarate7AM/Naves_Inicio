#include <SDL.h>
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
	bool EsLimitePantalla(Nave * objeto,int bandera);

	int opcionSeleccionada;
	Uint8 * keys;//Esta variable nos servira para ver si determinadas teclas estan o no pulsadas
	SDL_Event event;// La variable event de tipo evento de SDL nos servira para monitorizar el teclado

	SDL_Surface *screen;
	Nave *nave;
	/*Nave* enemigo;*/
	Nave *enemigoArreglo[10];

	Nave *menu;// Fondo del Menu
	Nave *textos;//Textos del menu
	Nave *fondo;//Fondo del juego

	int tick;
	int tiempoFrameInicial;
	int tiempoFrameFinal;

	Estado estado;
};