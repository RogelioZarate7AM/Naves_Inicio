#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Header.h" 
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	estado = ESTADO_INICIANDO;
	////ACT3: Mal, esta parte no va aqui, debe ir en el estado ESTADO_INICIANDO llamado desde un metodo llamado iniciando.
	Iniciando();

	//delete nave;
}
void CGame::Iniciando(){
	if (SDL_Init(SDL_INIT_VIDEO)<0)//si regresa 1 el init de video si se activo y regresa -1 si no se pudo iniciar. 
	{
		printf("No se pudo iniciar SDL: Error %s\n", SDL_GetError());//
		exit(EXIT_FAILURE);
	}
	screen= SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_SWSURFACE);//(ancho,alto,bpp,bandera)
	if (screen==NULL)
	{
		printf("No se puede inicializar el modo grafico: \n",SDL_GetError());
		getchar();
		exit(1);
	}
	SDL_WM_SetCaption( "Mi primer Juego", NULL );

	///ACT3 Hasta aqui esta mal.
	atexit(SDL_Quit);

	nave = new Nave(screen,"../Data/MiNave.bmp");

}
// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	delete(nave);
	SDL_FreeSurface(screen);
	SDL_Quit();
}

bool CGame::Start()
{

	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
	 
		//Maquina de estados
		switch(estado){
		case Estado::ESTADO_INICIANDO:
			Iniciando();
			estado =ESTADO_MENU;
			//{
			//	//nave=SDL_LoadBMP("../Data/MiNave.bmp");
			//	nave=IMG_LoadJPG_RW(SDL_RWFromFile("C://Users/RZ/Documents/GitHub/Naves_Inicio/Data/cuadro.jpg","rb"));
			//	SDL_Rect fuente;
			//	fuente.x = 582;
			//	fuente.y = 383;
			//	fuente.w = 321;
			//	fuente.h = 16;
			//	SDL_Rect destino;
			//	destino.x = 100;
			//	destino.y = 100;
			//	destino.w =100;
			//	destino.h = fuente.h;
			//	SDL_BlitSurface(nave,&fuente,screen,&destino);
			//}
			break;
		case Estado ::ESTADO_MENU:
		//	nave->PintarModulo(0,0,0,64,64);
			/*for (int i = 0; i < 100; i++)
			{
				
				nave ->PintarModulo(0,i,i);
				SDL_Delay(i);
			}*/
				SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));  //limpia la imagen 
			keys= SDL_GetKeyState(NULL);
			if(keys[SDLK_RIGHT])
			{
				nave->Mover(1);
			}//Los 3 casos siguientes son el primero aplicando a las demas direcciones
			if(keys[SDLK_LEFT])
			{
				nave->Mover(-1);
			}
			if(keys[SDLK_UP])
			{
				nave->Mover2(-1);
			}
				if(keys[SDLK_DOWN])
			{
				nave->Mover2(1);
			}
			
				nave->Pintar();
			break;
		case Estado ::ESTADO_JUGANDO:
			break;
		case Estado ::ESTADO_TERMINANDO:
			break;
		case Estado ::ESTADO_FINALIZANDO:
			salirJuego = true;
			break;
		};
		while(SDL_PollEvent(&event))//Aque SDL creara una lista de eventes ocurridos
		{
			if(event.type==SDLK_ESCAPE){salirJuego=true;}//Si se detecta una salida de SDL o...
			if(event.type==SDL_KEYDOWN){}
		}
		SDL_Flip(screen);//Este codigo esta provicionalmente aqui
    }
	return true;
}
