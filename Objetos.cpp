#include "Objetos.h"

void Objetos::inicializar(string nome, string caminho, int animacoes, int frames, float posicaox, float posicaoy, int valor, bool destrutivel)
{
	this->nome = nome;
	this->caminho = caminho;
	posicao.x = posicaox;
	posicao.y = posicaoy;
	setarPosicoesRespawn(320, 425, 145, 600, -60); // Posições de respawn dos objetos.
	this->valor = valor;
	this->destrutivel = destrutivel;
	vivo = true;
	velocidade = 1;
	srand(time(0));
	tInicio = gTempo.getTicks();


	if (!gRecursos.carregouSpriteSheet(this->nome))
		gRecursos.carregarSpriteSheet(this->nome, this->caminho, animacoes, frames);
	if (!gRecursos.carregouAudio("facada"))
		gRecursos.carregarAudio("facada", "bin/assets/audios/somfaca.mp3");
	

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
				gAudios.tocar("facada", 15);
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
	vivo = true;
	if (sprite.getAnimacao() == 1)
		sprite.setAnimacao(0, true);

	if (valor == -100)
		posicao = posicoes[0];
	else
	{
		sorteado = rand() % 3 + 1;

		if (sorteado == 1)
			posicao = posicoes[1];
		else if (sorteado == 2)
			posicao = posicoes[2];
		else if (sorteado == 3)
			posicao = posicoes[3];
	}
}	


void Objetos::setarPosicoesRespawn(int x0, int x1, int x2, int x3, int y)
{
	posicoes[0].x = x0;
	posicoes[1].x = x1;
	posicoes[2].x = x2;
	posicoes[3].x = x3;
	for (int p = 0; p < 4; p++)
		posicoes[p].y = y * p + y;
}

void Objetos::finalizar()
{
	gRecursos.descarregarSpriteSheet(nome);
	gRecursos.descarregarAudio("facada");
}

void Objetos::setVelocidade()
{	
	if (tempo >= 0)
		velocidade = 1;
	if (tempo >= 21)
		velocidade = 2;
	if (tempo >= 101)
		velocidade = 4;
	if (tempo >= 151)
		velocidade = 5;

	posicao.y = posicao.y + velocidade;
}

void Objetos::testarColisao(Vetor2D posPersonagem, Sprite sprPersonagem)
{

	if (uniTestarColisao(sprite, posicao.x, posicao.y, 0, sprPersonagem, posPersonagem.x, posPersonagem.y, 0))
	{
		posicao.y = -120;
	}
}






