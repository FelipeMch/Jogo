#include "Objetos.h"

void Objetos::inicializar(string nome, string caminho, int animacoes, int frames, float posicaox, float posicaoy, int valor, bool destrutivel)
{
	this->nome = nome;
	this->caminho = caminho;
	posicao.x = posicaox;
	posicao.y = posicaoy;
	posicoes[0].x = 320;
	posicoes[1].x = 425;
	posicoes[2].x = 185;
	posicoes[3].x = 600;
	for (int p = 0; p < 4; p++)
		posicoes[p].y = -100;
	this->valor = valor;
	this->destrutivel = destrutivel;
	vivo = true;
	velocidade = 2;
	srand(time(0));
	tInicio = gTempo.getTicks();


	if (!gRecursos.carregouSpriteSheet(this->nome))
		gRecursos.carregarSpriteSheet(this->nome, this->caminho, animacoes, frames);

	sprite.setSpriteSheet(this->nome);

}

void Objetos::desenhar()
{
	if (vivo)
	{
		sprite.desenhar(posicao.x, posicao.y);
		sprite.avancarAnimacao();
		sprite.setVelocidadeAnimacao(15);
	
	}
}

int Objetos::executar(Vetor2D posPersonagem, Sprite sprPersonagem, bool verificarMorte)
{
	setVelocidade();
	tempo = gTempo.getTempoAteTickAtual(tInicio);

	if (uniTestarColisao(sprite, posicao.x, posicao.y, 0, sprPersonagem, posPersonagem.x, posPersonagem.y, 0) && vivo)
	{
		
		if (destrutivel && valor > 0)
		{
			vivo = false;
			resetarPosicao();
		}
		if (destrutivel && verificarMorte == true && valor < 0)
		{	

			if (sprite.getAnimacao() == 0)
			{
				sprite.setAnimacao(1, false);
			}
			else
			{
				if (sprite.terminouAnimacao())
				{
					vivo = false;
					resetarPosicao();
				}
			}
		}
		else
		{
		
		}

		return valor;
	}

	if (posicao.y > 800)
		resetarPosicao();

	return 0;
}

void Objetos::resetarPosicao()
{
	sorteado = rand() % 4;
	vivo = true;
	if(sprite.getAnimacao() == 1)
		sprite.setAnimacao(0, true);
	if (sorteado == 0)
		posicao = posicoes[0];
	else if (sorteado == 1)
		posicao = posicoes[1];
	else if (sorteado == 2)
		posicao = posicoes[2];
	else if (sorteado == 3)
		posicao = posicoes[3];
	
	
}	


void Objetos::finalizar()
{
	gRecursos.descarregarSpriteSheet(nome);
}

void Objetos::setVelocidade()
{
	if(tempo < 15)
		if (posicao.y < gJanela.getAltura() + 60) //Faz o objeto andar.
			posicao.y = posicao.y + velocidade;
	if (tempo >= 15)
	{
		if (posicao.y < gJanela.getAltura() + 60) //Faz o objeto andar.
			posicao.y = posicao.y + velocidade;
	}
}





