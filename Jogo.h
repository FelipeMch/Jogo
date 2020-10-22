#pragma once
#include "Fase.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void executar();
	void finalizar();

protected:

	Fase fase;
	Uint64 tInicio;
	int tempo;
	Texto texto;
	
};

