#include "SpriteDef.h"
#include "Header.h"

SpriteDef::SpriteDef(){
	modulos[0].id=MODULO_MINAVE_NAVE;//Nave
	modulos[0].x=0;
	modulos[0].y=0;
	modulos[0].w=64;
	modulos[0].h=64;

	modulos[1].id=MODULO_MENU_FONDO;//Fondo
	modulos[1].x=0;
	modulos[1].y=0;
	modulos[1].w=WIDTH_SCREEN;
	modulos[1].h=HEIGHT_SCREEN;

	modulos[2].id=MODULO_ENEMIGO_NAVE;//Nave enemiga
	modulos[2].x=0;
	modulos[2].y=0;
	modulos[2].w=54;
	modulos[2].h=61;
	
	
	modulos[3].id=MODULO_TEXTOS_TITULO;//Titulo
	modulos[3].x=140;
	modulos[3].y=30;
	modulos[3].w=380;
	modulos[3].h=75;

	modulos[4].id=MODULO_TEXTOS_NOMBRE;//Nombre Anio
	modulos[4].x=135;
	modulos[4].y=240;
	modulos[4].w=350;
	modulos[4].h=30;

	modulos[5].id=MODULO_TEXTOS_MENU_OPCION1;//Iniciar
	modulos[5].x=200;
	modulos[5].y=150;
	modulos[5].w=60;
	modulos[5].h=20;

	modulos[6].id=MODULO_TEXTOS_MENU_OPCION2;//Salir
	modulos[6].x=200;
	modulos[6].y=198;
	modulos[6].w=50;
	modulos[6].h=20;

	modulos[7].id=MODULO_TEXTOS_MENU_OPCION1_SELECCIONADO;//Iniciar verde
	modulos[7].x=310;
	modulos[7].y=150;
	modulos[7].w=50;
	modulos[7].h=20;

	modulos[8].id=MODULO_TEXTOS_MENU_OPCION2_SELECCIONADO;//Salir verde
	modulos[8].x=310;
	modulos[8].y=200;
	modulos[8].w=50;
	modulos[8].h=20;


}