#include "Fase.h"

void Fase::inicializar()
{
	if(!gRecursos.carregouSpriteSheet("background"))
		gRecursos.carregarSpriteSheet("background", "bin/assets/imagens/fundopraia.png", 1, 1);

	fundo.setSpriteSheet("background");

	//Inicialização do Personagem e objetos.
	persoPrincipal.inicializar();
	for (int c = 0; c < 4; c++)
		cocos[c].inicializar("coco", "bin/assets/imagens/cocoteste.png", 1, 1, 300, 100 + c * 80, 1, 1);
	guarda.inicializar("guarda", "bin/assets/imagens/guardateste.png", 1, 1, 425, 50, -500, 0);
	tubarao.inicializar("tubarao", "bin/assets/imagens/tubarao.png", 1, 1, 320, 100, -500, 1);

	//Inicialação do tempo.
	tInicio = gTempo.getTicks();
	gRecursos.carregarFonte("fonte", "bin/assets/fontes/fonte.ttf", 17);
	texto.setFonte("fonte");
	texto.setCor(3, 0, 147);

	posicoes[0].x = gJanela.getLargura() / 2;
	posicoes[0].y = gJanela.getAltura() / 2;
	posicoes[1].x = gJanela.getLargura() / 2;
	posicoes[1].y = gJanela.getAltura() / 2 - gJanela.getAltura();
	velocidade = 2;
}

void Fase::desenhar()
{
	fundo.desenhar(posicoes[0].x, posicoes[0].y);
	fundo.desenhar(posicoes[1].x, posicoes[1].y);
	persoPrincipal.desenhar();
	for (int c = 0; c < 4; c++)
		cocos[c].desenhar();
	guarda.desenhar();
	tubarao.desenhar();
}

void Fase::executar()
{
	//Movimentação da fase
	posicoes[0].y = posicoes[0].y + velocidade;
	posicoes[1].y = posicoes[1].y + velocidade;
	if (posicoes[0].y == +gJanela.getAltura() / 2)
		posicoes[1].y = gJanela.getAltura() / 2 - gJanela.getAltura();
	if (posicoes[1].y == +gJanela.getAltura() / 2)
		posicoes[0].y = gJanela.getAltura() / 2 - gJanela.getAltura();

	//Atualizações das execuções
	persoPrincipal.executar();
	for (int c = 0; c < 4; c++)
		cocos[c].executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite(), persoPrincipal.getPodeMatar());
	guarda.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite(), persoPrincipal.getPodeMatar());
	tubarao.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite(), persoPrincipal.getPodeMatar());
	
	//Atualizações das colisões
	for (int c = 0; c < 4; c++)
		persoPrincipal.atualizarColisao(cocos[c].executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite(), persoPrincipal.getPodeMatar()));
	persoPrincipal.atualizarColisao(guarda.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite(), persoPrincipal.getPodeMatar()));
	persoPrincipal.atualizarColisao(tubarao.executar(persoPrincipal.getPosicao(), persoPrincipal.getSprite(), persoPrincipal.getPodeMatar()));


	//Atualizações de tempo
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
