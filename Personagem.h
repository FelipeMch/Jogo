#pragma once
#include "libUnicornio.h"



class Personagem
{
public:

	void inicializar();
	void executar();
	void finalizar();
	void desenhar();
	Vetor2D getPosicao() { return posicao; }
	Sprite getSprite() { return spritePersoPrincipal; }
	void atualizarColisao(int v);
	void resetarPosicao();

protected:

	Sprite spritePersoPrincipal;
	Vetor2D posicao, posicaoInicial;
	float velocidade;
	
};

