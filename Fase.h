#pragma once
#include "libUnicornio.h"
#include "Obstaculos.h"

class Fase
{
public:

	void inicializar(Obstaculos *o, int nivel);
	void finalizar();
	void executar();

protected:

	Sprite obstaculo;

};

