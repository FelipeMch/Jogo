#include "Fase.h"




void Fase::inicializar(Obstaculos* o, int nivel)
{
	if (nivel == 0)
	{
		if (!gRecursos.carregouSpriteSheet("armario"))
		{
			gRecursos.carregarSpriteSheet("armario", "assets/imagens/ArmarioPorta.png");
		}
		obstaculo.setSpriteSheet("armario");
	}
}

	fundo.setSpriteSheet("background");

	posicao.x = gJanela.getLargura() / 2;
	posicao.y = gJanela.getAltura() / 2;

	persoPrincipal.inicializar();
	coco.inicializar("coco", "bin/assets/imagens/cocoteste.png", 1, 1, 300, 300, 1, 1);
	guarda.inicializar("guarda", "bin/assets/imagens/guardateste.png", 1, 1, 425, 200, -500, 0);
	//tubarao.inicializar("castelo", "bin/assets/imagens/tubarao.png", 1, 1, 320, 400, -1, 1);
}

void Fase::desenhar()
{
	fundo.desenhar(posicao.x, posicao.y);
	persoPrincipal.desenhar();
	coco.desenhar();
	guarda.desenhar();
	//tubarao.desenhar();
	
}

void Fase::executar()
{
	persoPrincipal.executar();
	coco.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite());
	guarda.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite());
	//tubarao.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite());
	
	persoPrincipal.atualizarColisao(coco.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite()));
	persoPrincipal.atualizarColisao(guarda.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite()));
	//persoPrincipal.atualizarColisao(tubarao.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite()));
}

void Fase::finalizar()
{
	gRecursos.descarregarSpriteSheet("background");
	persoPrincipal.finalizar();
	coco.finalizar();
	guarda.finalizar();
	//tubarao.finalizar();
}
