#pragma once
#include "libUnicornio.h"
#include <ctime>


class Personagem
{
public:

	void inicializar();
	void executar();
	void finalizar();
	void desenhar();
	Vetor2D getPosicao() { return posicao; }
	Sprite getSprite() { return spritePersoPrincipal; }
	bool getPodeMatar() { return podeMatar; }
	bool getMorte() { return vivo; }
	int getPontos() { return pontos; }
	void atualizarColisao(int v, bool morte);
	void resetarPosicao();

protected:

	Sprite spritePersoPrincipal;
	Vetor2D posicao, posicaoInicial;
	float velocidade;
	int pontos, tempo;
	Uint64 tInicio;
	bool podeMatar, vivo;
	
	
};

