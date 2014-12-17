#include "Game.h"

void CGame::inicialicializandoStage()
{
	nivel[0].fondoNivel=0;
	nivel[0].balasMaximas=3;
	nivel[0].numeroEnemigosAEliminar=10;
	nivel[0].numeroEnemigosVisibles=2;
	nivel[0].velocidadBalasEnemigo=5;
	nivel[0].velocidadBalasPropias=10;
	nivel[0].velocidadNaveEnemigo=10;
	nivel[0].velocidadNavePropia=5;
	nivel[0].vidaEnemigo=1;

	nivel[1].fondoNivel=0;
	nivel[1].balasMaximas=5;
	nivel[1].numeroEnemigosAEliminar=15;
	nivel[1].numeroEnemigosVisibles=5;
	nivel[1].velocidadBalasEnemigo=10;
	nivel[1].velocidadBalasPropias=15;
	nivel[1].velocidadNaveEnemigo=15;
	nivel[1].velocidadNavePropia=10;
	nivel[1].vidaEnemigo=2;

}