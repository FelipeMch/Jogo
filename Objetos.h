#pragma once
#include "Personagem.h"

class Objetos
{
public:

	void inicializar(string nome, string caminho, int animacoes, int frames, float posicaox, float posicaoy, int valor, bool destrutivel);
	void desenhar();
	int executar(Vetor2D posPersonagem, Sprite sprPersonagem, bool verificarMorte);
	void resetarPosicao();
	bool getDestrutivel() { return destrutivel; }
	Vetor2D getposicao() { return posicao; }
	Vetor2D getposicoes() { return posicoes[0]; }
	void setarPosicoesRespawn(int x0, int x1, int x2, int x3, int y);
	Sprite getSprite() { return sprite; }
	void finalizar();
	void setVelocidade();
	void testarColisao(Vetor2D posPersonagem, Sprite sprPersonagem);

	

protected:

	Sprite sprite;
	string nome, caminho;
	Vetor2D posicao, posicoes[4];
	bool vivo, destrutivel;
	int valor, velocidade = 0, sorteado, tempo;
	Uint64 tInicio;
	
	
};

