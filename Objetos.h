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
	void finalizar();
	

protected:

	Sprite sprite;
	string nome, caminho;
	Vetor2D posicao, posicaoInicial, posicoes[3];
	bool vivo, destrutivel;
	int valor, velocidade = 0, tempo, sorteado;
	Uint64 tInicio;

	
	
	
};

