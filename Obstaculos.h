#pragma once
#include "Jogo.h"

class Obstaculos
{

	void inicializar();
	void finalizar();
	void executar();

protected:
	Sprite obstaculo;

	Fase fase;

};

