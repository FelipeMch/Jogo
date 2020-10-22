#include "Fase.h"

void Fase::inicializar()
{
	if(!gRecursos.carregouSpriteSheet("background"))
		gRecursos.carregarSpriteSheet("background", "bin/assets/imagens/fundopraia.png", 1, 1);

	fundo.setSpriteSheet("background");

	posicoes[0].x = gJanela.getLargura() / 2;
	posicoes[0].y = gJanela.getAltura() / 2;

	posicoes[1].x = gJanela.getLargura() / 2;
	posicoes[1].y = gJanela.getAltura() / 2 - gJanela.getAltura();

	persoPrincipal.inicializar();
	
	for (int c = 0; c < 4; c++)
		cocos[c].inicializar("coco", "bin/assets/imagens/cocoteste.png", 1, 1, 300, 300 + c * 80, 1, 1);
	
	guarda.inicializar("guarda", "bin/assets/imagens/guardateste.png", 1, 1, 425, 200, -500, 0);
	//tubarao.inicializar("castelo", "bin/assets/imagens/tubarao.png", 1, 1, 320, 400, -1, 1);

	tInicio = gTempo.getTicks();

	gRecursos.carregarFonte("fonte", "bin/assets/fontes/fonte.ttf", 17);
	texto.setFonte("fonte");
	texto.setCor(3, 0, 147);
}

void Fase::desenhar()
{
	fundo.desenhar(posicoes[0].x, posicoes[0].y);
	fundo.desenhar(posicoes[1].x, posicoes[1].y);
	
	persoPrincipal.desenhar();
	for (int c = 0; c < 4; c++)
		cocos[c].desenhar();
	guarda.desenhar();
	//tubarao.desenhar();
}

void Fase::executar()
{
	
	//posicoes[0].y++;
	//posicoes[1].y++;

	//if (posicoes[0].y == +gJanela.getAltura() / 2)
	//	posicoes[0].y = gJanela.getAltura() / 2 - gJanela.getAltura();
	//
	//if (posicoes[1].y == +gJanela.getAltura() / 2)
	//	posicoes[1].y = gJanela.getAltura() / 2 - gJanela.getAltura();

	persoPrincipal.executar();
	
	for (int c = 0; c < 4; c++)
		cocos[c].executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite());
	
	guarda.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite());
	//tubarao.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite());
	
	for (int c = 0; c < 4; c++)
		persoPrincipal.atualizarColisao(cocos[c].executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite()));
	
	persoPrincipal.atualizarColisao(guarda.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite()));
	//persoPrincipal.atualizarColisao(tubarao.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite()));

	tempo = gTempo.getTempoAteTickAtual(tInicio);
	texto.setString("Pontos " + to_string(tempo));
	texto.desenhar(gJanela.getLargura() / 4, gJanela.getAltura() / 10);
}

void Fase::finalizar()
{
	gRecursos.descarregarSpriteSheet("background");
	persoPrincipal.finalizar();
	for (int c = 0; c < 4; c++)
		cocos[c].finalizar();
	
	guarda.finalizar();
	tubarao.finalizar();
}
