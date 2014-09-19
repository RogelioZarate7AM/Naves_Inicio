#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>

CGame::CGame(){
	estado = ESTADO_INICIANDO;
	//SDL_Surface*screen;
	//if (SDL_Init(SDL_INIT_VIDEO)<0)//si regresa 1 el init de video si se activo y regresa -1 si no se pudo iniciar. 
	//{
	//	printf("No se pudo iniciar SDL: %s\n", SDL_GetError());//
	//	exit(EXIT_FAILURE);
	//}
	//screen= SDL_SetVideoMode(640,480,24,SDL_HWSURFACE);//(ancho,alto,bpp,bandera)
	//if (screen==NULL)
	//{
	//	printf("No se puede inicializar el modo grafico: \n",SDL_GetError());
	//	exit(1);
	//}
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case Estado::ESTADO_INICIANDO:
			break;
		case Estado ::ESTADO_MENU:	
			break;
		case Estado ::ESTADO_JUGANDO:
			break;
		case Estado ::ESTADO_TERMINANDO:
			break;
		case Estado ::ESTADO_FINALIZANDO:
			salirJuego = true;
			break;
		};
    }
	return true;
}
