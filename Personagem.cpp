#include "Personagem.h"

void Personagem::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("spritePersoPrincipal"))
		gRecursos.carregarSpriteSheet("spritePersoPrincipal", "bin/assets/imagens/personagem.png", 1, 4);

	spritePersoPrincipal.setSpriteSheet("spritePersoPrincipal");
	spritePersoPrincipal.setVelocidadeAnimacao(4);
	
	velocidade = 3;
	posicao.x = gJanela.getLargura() / 2;
	posicao.y = 720;
	posicaoInicial = posicao;
	
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


