#include "Personagem.h"

void Personagem::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("spritePersoPrincipal") && !gRecursos.carregouSpriteSheet("FacadaCorrendo"))
	{
		gRecursos.carregarSpriteSheet("spritePersoPrincipal", "bin/assets/imagens/personagemteste.png", 1, 4);
		gRecursos.carregarSpriteSheet("FacadaCorrendo", "bin/assets/imagens/teste1faca.png", 1, 6);
	}

	spritePersoPrincipal.setSpriteSheet("spritePersoPrincipal");
	
	velocidade = 3;
	posicao.x = gJanela.getLargura() / 2;
	posicao.y = 720;
	posicaoInicial = posicao;
	podeMatar = false;
	
}

void Personagem::desenhar()
{
	spritePersoPrincipal.desenhar(posicao.x, posicao.y);
	spritePersoPrincipal.avancarAnimacao();
}


void Personagem::executar()
{
	if ((gTeclado.segurando[TECLA_ESQ] || gTeclado.segurando[TECLA_A]) && posicao.x > spritePersoPrincipal.getLargura() / 2)
		posicao.x -= velocidade;
	if ((gTeclado.segurando[TECLA_DIR] || gTeclado.segurando[TECLA_D]) && posicao.x < 600)
		posicao.x += velocidade;	
	if ((gTeclado.segurando[TECLA_BAIXO] || gTeclado.segurando[TECLA_S]) && posicao.y < 740)
		posicao.y += velocidade;	
	if ((gTeclado.segurando[TECLA_CIMA] || gTeclado.segurando[TECLA_W]) && posicao.y > spritePersoPrincipal.getAltura() / 2)
		posicao.y -= velocidade;
	if (gTeclado.segurando[TECLA_ESPACO])
	{ 
		podeMatar = true;
		spritePersoPrincipal.setSpriteSheet("FacadaCorrendo");
		spritePersoPrincipal.avancarAnimacao();
		spritePersoPrincipal.setVelocidadeAnimacao(2);
	}
	else
	{
		podeMatar = false;
		spritePersoPrincipal.setSpriteSheet("spritePersoPrincipal");
		spritePersoPrincipal.avancarAnimacao();
		spritePersoPrincipal.setVelocidadeAnimacao(2);
	}
}

void Personagem::atualizarColisao(int v)
{

	if (v > 0)
	{

	}

	if (v == -500)
	{
		resetarPosicao();
	}
}

void Personagem::resetarPosicao()
{
	posicao = posicaoInicial;
}


void Personagem::finalizar()
{
	gRecursos.descarregarSpriteSheet("persoPrincipal");
}


