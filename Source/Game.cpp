#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Header.h" 
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame()
{
	tiempoFrameInicial=0;
	estado = ESTADO_INICIANDO;
	Iniciando();

	//delete nave;
}
void CGame::Iniciando(){
	if (SDL_Init(SDL_INIT_VIDEO)<0)//si regresa 1 el init de video si se activo y regresa -1 si no se pudo iniciar. 
	{
		printf("No se pudo iniciar SDL: Error %s\n", SDL_GetError());//
		exit(EXIT_FAILURE);
	}
	screen= SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE);//(ancho,alto,bpp,bandera)
	if (screen==NULL)
	{
		printf("No se puede inicializar el modo grafico: \n",SDL_GetError());
		getchar();
		exit(1);
	}
	SDL_WM_SetCaption( "Mi primer Juego", NULL );

	atexit(SDL_Quit);

	fondo=new Nave(screen,"../Data/fondo.bmp",0,0,1);
	nave = new Nave(screen,"../Data/MiNave.bmp",(WIDTH_SCREEN/2),(HEIGHT_SCREEN-80),MODULO_MINAVE_NAVE);
	menu= new Nave(screen,"../Data/menu.bmp",0,0,MODULO_MENU_FONDO);
	textos=new Nave(screen,"../Data/textos.bmp",0,0,-1);
	//textos[0]= new Nave(screen,"../Data/textos.bmp",15,430,3);//NombreAnio  15,430 posicion en pantalla, 3 es el modulo que se pinta
	//textos[1]= new Nave(screen,"../Data/textos.bmp",140,40,4);//Titulo
	//textos[2]= new Nave(screen,"../Data/textos.bmp",300,240,5);//Inicio
	//textos[3]= new Nave(screen,"../Data/textos.bmp",300,270,6);//Salir
	
//	enemigo = new Nave(screen,"../Data/enemigo.bmp",0,0);

	for (int i = 0; i < 10; i++)
	{
		enemigoArreglo[i] = new Nave(screen,"../Data/enemigo.bmp",i*60,0,MODULO_ENEMIGO_NAVE);
		enemigoArreglo[i]->SetAutoMovimiento(false);
		enemigoArreglo[i]->SetPasoLimite(4);
	}

	tick=0;
	opcionSeleccionada=MODULO_TEXTOS_MENU_OPCION1;

//	enemigo->SetAutoMovimiento(false);
//	enemigo->SetPasoLimite(4);

}
// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	delete(nave);
	//delete(keys);
	//delete(enemigo);
	//delete *enemigoArreglo;
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
			//estado =ESTADO_JUGANDO;
			estado=ESTADO_MENU;
			break;
		case Estado ::ESTADO_MENU:
			menu->Pintar();
			textos->Pintar(MODULO_TEXTOS_TITULO,150,50);
			textos->Pintar(MODULO_TEXTOS_NOMBRE,0,450);
			Menu();
		//estado=ESTADO_JUGANDO;
			break;
		case Estado ::ESTADO_JUGANDO:
			 
		//enemigo->Actualizar();
			for (int i = 0; i < 10; i++)
			{
				enemigoArreglo[i]->Actualizar();
			}
			MoverEnemigo();
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));  //limpia la imagen 

			keys= SDL_GetKeyState(NULL);
			if(keys[SDLK_RIGHT])
			{ 
				if(!EsLimitePantalla(nave,BORDE_DERECHO))
				nave->Mover(8);
			}//Los 3 casos siguientes son el primero aplicando a las demas direcciones
			if(keys[SDLK_LEFT])
			{
				if(!EsLimitePantalla(nave,BORDE_IZQUIERDO))
				nave->Mover(-8);
			}
			if(keys[SDLK_UP])
			{
				if(!EsLimitePantalla(nave,BORDE_SUPERIOR))
				nave->Mover2(-8);
			}
			if(keys[SDLK_DOWN])
			{
				if(!EsLimitePantalla(nave,BORDE_INFERIOR))
				nave->Mover2(8);
			}

			    fondo->Pintar();
				nave->Pintar();
		//		enemigo->Pintar();
				for(int i=0;i<10;i++)
				{
					enemigoArreglo[i]->Pintar();
				}
			//nave->Pintar();
			break;
		case Estado ::ESTADO_TERMINANDO:
			break;
		case Estado ::ESTADO_FINALIZANDO:
			salirJuego = true;
			break;
		};
		while(SDL_PollEvent(&event))//Aque SDL creara una lista de eventes ocurridos
		{
			if(event.type==SDL_QUIT){salirJuego=true;}//Si se detecta una salida de SDL o...
			if(event.type==SDL_KEYDOWN){}
		}
		SDL_Flip(screen);//Este codigo esta provicionalmente aqui
		//calculando FPS
		tiempoFrameFinal=SDL_GetTicks();
		while(tiempoFrameFinal<(tiempoFrameInicial+FPS_DELAY))
			{
				tiempoFrameFinal=SDL_GetTicks();
				SDL_Delay(1);
			}

		printf("Frames:%d Tiempo:%d Tiempo promedio:%f Tiempo por frame:%d FPS:%f\n",tick,SDL_GetTicks(),(float)SDL_GetTicks()/(float)tick,tiempoFrameFinal- tiempoFrameInicial,1000.0f/(float)(tiempoFrameFinal-tiempoFrameInicial));
		tiempoFrameInicial=tiempoFrameFinal;
		tick++;
	}
	return true;
}

bool CGame::EsLimitePantalla(Nave * objeto, int bandera)
{
	if (bandera&BORDE_IZQUIERDO)
	if (objeto->ObtenerX()<=0)
		return true;
	if(bandera&BORDE_SUPERIOR)
	if (objeto->ObtenerY()<=0)
		return true;
	if(bandera&BORDE_DERECHO)
	if (objeto->ObtenerX()>=WIDTH_SCREEN-objeto->ObtenerW())
		return true;
	if(bandera&BORDE_INFERIOR)
	if (objeto->ObtenerY()>=HEIGHT_SCREEN-objeto->ObtenerH())
		return true;
	return false;
}
void CGame::MoverEnemigo()
{
//	if(enemigo->ObtenerPasoActual()==0)
//		if(!EsLimitePantalla(enemigo,BORDE_DERECHO))
//	         enemigo->Mover(1);//Derecha
//		else
//		{
//			enemigo->IncrementarPasoAcutal();
//			//enemigo->IncrementarPasoAcutal();
//		}
//	if(enemigo->ObtenerPasoActual()==1)
//		if(!EsLimitePantalla(enemigo,BORDE_INFERIOR))
//			enemigo->Mover2(1);
//		else
//		{
//			enemigo->IncrementarPasoAcutal();
//		}
//	if(enemigo->ObtenerPasoActual()==2)
//		if(!EsLimitePantalla(enemigo,BORDE_IZQUIERDO))
//			enemigo->Mover(-1);
//		else
//		{
//			enemigo->IncrementarPasoAcutal();
//		}
//
//	if(enemigo->ObtenerPasoActual()==3)
//		if(!EsLimitePantalla(enemigo,BORDE_INFERIOR))
//			enemigo->Mover2(1);
//		else
//		{
//			enemigo->IncrementarPasoAcutal();
//		}
//
		for (int i = 0; i < 10; i++)
		{
			if(enemigoArreglo[i]->ObtenerPasoActual()==0)
				if(!EsLimitePantalla(enemigoArreglo[i],BORDE_DERECHO))
					{
						enemigoArreglo[i]->Mover(30);//Derecha
					}
				else
					{
						enemigoArreglo[i]->IncrementarPasoAcutal();
						//enemigoArreglo[i]->IncrementarPasoAcutal();
					}
			if(enemigoArreglo[i]->ObtenerPasoActual()==1)
				if(!EsLimitePantalla(enemigoArreglo[i],BORDE_INFERIOR))
					{
						enemigoArreglo[i]->Mover2(30);
					}
				else
					{
						enemigoArreglo[i]->IncrementarPasoAcutal();
					}
			if(enemigoArreglo[i]->ObtenerPasoActual()==2)
				if(!EsLimitePantalla(enemigoArreglo[i],BORDE_IZQUIERDO))
					{	
						enemigoArreglo[i]->Mover(-30);
					}
				else
					{
						enemigoArreglo[i]->IncrementarPasoAcutal();
						//enemigoArreglo[i]->IncrementarPasoAcutal();
					}
			if(enemigoArreglo[i]->ObtenerPasoActual()==3)
				if(!EsLimitePantalla(enemigoArreglo[i],BORDE_SUPERIOR))
				{	enemigoArreglo[i]->Mover2(-30);}
				else
				{
					enemigoArreglo[i]->IncrementarPasoAcutal();
				}
}
}
void CGame::Menu()
{
	
	for (int i = MODULO_TEXTOS_MENU_OPCION1,j=0; i <MODULO_TEXTOS_MENU_OPCION2 ; i++,j++)
	{
		if (i=opcionSeleccionada)
		{
			textos->Pintar(i+2,200,180+(j*80));
		}
		else
		{
			textos->Pintar(i,200,180+(j*80));
		}
	
	}
}