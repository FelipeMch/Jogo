#pragma once
#include "libUnicornio.h"



class Personagem
{
public:

	void inicializar();
	void executar();
	void finalizar();
	void desenhar();

protected:

	Sprite spritePersoPrincipal;
	Vetor2D posicao;
	float velocidade;
	
};

