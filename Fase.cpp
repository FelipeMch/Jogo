#include "Fase.h"

void Fase::inicializar()
{
	if(!gRecursos.carregouSpriteSheet("background"))
		gRecursos.carregarSpriteSheet("background", "bin/assets/imagens/fundopraia.png", 1, 1);

	fundo.setSpriteSheet("background");

	posicao.x = gJanela.getLargura() / 2;
	posicao.y = gJanela.getAltura() / 2;

	persoPrincipal.inicializar();
	coco.inicializar("coco", "bin/assets/imagens/cocoteste.png", 1, 1, 300, 300, 1, 1);
	guarda.inicializar("guarda", "bin/assets/imagens/guardateste.png", 1, 1, 425, 400, -500, 0);
	//castelo.inicializar("castelo", "bin/assets/imagens/castelo1.png", 1, 1, 320, 400, 1, 1);
}

void Fase::desenhar()
{
	fundo.desenhar(posicao.x, posicao.y);
	persoPrincipal.desenhar();
	
	
	coco.desenhar();
	guarda.desenhar();
	//castelo.desenhar();
	
}

void Fase::executar()
{
	persoPrincipal.executar();
	coco.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite());
	guarda.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite());
	
	persoPrincipal.atualizarColisao(coco.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite()));
	persoPrincipal.atualizarColisao(guarda.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite()));
}

void Fase::finalizar()
{
	gRecursos.descarregarSpriteSheet("background");
	persoPrincipal.finalizar();
	coco.finalizar();
	guarda.finalizar();
}
