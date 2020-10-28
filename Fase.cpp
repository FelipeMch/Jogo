#include "Fase.h"

void Fase::inicializar(Personagem *personagem)
{
	if(!gRecursos.carregouSpriteSheet("background"))
		gRecursos.carregarSpriteSheet("background", "bin/assets/imagens/praiainicial.png", 1, 3);
	

	fundo.setSpriteSheet("background");


	//Inicialização do Personagem e objetos.
	persoPrincipal = personagem; // associa personagem do jogo com o da fase;
	persoPrincipal->inicializar();
	for (int c = 0; c < 2; c++)
		cocos[c].inicializar("coco", "bin/assets/imagens/cocoteste.png", 1, 1, 300, 0 + c * -80, 10, true);
	guarda.inicializar("guarda", "bin/assets/imagens/guardateste.png", 1, 1, 425, -100, -500, false);
	tubarao.inicializar("tubarao", "bin/assets/imagens/tubarao.png", 1, 1, 320, -240, -100, true);
	

	//Inicialação do tempo.
	tInicio = gTempo.getTicks();
	gRecursos.carregarFonte("fonte", "bin/assets/fontes/fonte.ttf", 17);
	texto.setFonte("fonte");
	texto.setCor(3, 0, 147);
	

	posicoes[0].x = gJanela.getLargura() / 2;
	posicoes[0].y = gJanela.getAltura() / 2;
	posicoes[1].x = gJanela.getLargura() / 2;
	posicoes[1].y = gJanela.getAltura() / 2 - gJanela.getAltura();
	velocidade = 4;
	
}

void Fase::desenhar()
{
	fundo.desenhar(posicoes[0].x, posicoes[0].y);
	fundo.desenhar(posicoes[1].x, posicoes[1].y);
	fundo.avancarAnimacao();
	fundo.setVelocidadeAnimacao(0.6);
	persoPrincipal->desenhar();
	for (int c = 0; c < 2; c++)
		cocos[c].desenhar();
	guarda.desenhar();
	tubarao.desenhar();
}

void Fase::executar()
{
	//Atualizações de tempo
	tempo = gTempo.getTempoAteTickAtual(tInicio);
	texto.setString("Pontos " + to_string(tempo));
	texto.desenhar(gJanela.getLargura() / 4, gJanela.getAltura() / 10);	

	//Movimentação da fase
	controladorVelocidade();

	//Atualizações das execuções
	persoPrincipal->executar();
	for (int c = 0; c < 2; c++)
		cocos[c].executar(persoPrincipal->getPosicao(), persoPrincipal->getSprite(), persoPrincipal->getPodeMatar());
	guarda.executar(persoPrincipal->getPosicao(), persoPrincipal->getSprite(), persoPrincipal->getPodeMatar());
	tubarao.executar(persoPrincipal->getPosicao(), persoPrincipal->getSprite(), persoPrincipal->getPodeMatar());

	//Atualizações das colisões
	for (int c = 0; c < 2; c++)
		persoPrincipal->atualizarColisao(cocos[c].executar(persoPrincipal->getPosicao(), persoPrincipal->getSprite(), persoPrincipal->getPodeMatar()), cocos[c].getDestrutivel());
	persoPrincipal->atualizarColisao(guarda.executar(persoPrincipal->getPosicao(), persoPrincipal->getSprite(), persoPrincipal->getPodeMatar()), guarda.getDestrutivel());
	persoPrincipal->atualizarColisao(tubarao.executar(persoPrincipal->getPosicao(), persoPrincipal->getSprite(), persoPrincipal->getPodeMatar()), tubarao.getDestrutivel());


}

void Fase::finalizar()
{
	gRecursos.descarregarSpriteSheet("background");
	persoPrincipal->finalizar();
	for (int c = 0; c < 2; c++)
		cocos[c].finalizar();
	guarda.finalizar();
	tubarao.finalizar();
}

void Fase::controladorVelocidade()
{
	/*if (tempo >= 7)
		velocidade = 2;*/

	posicoes[0].y = posicoes[0].y + velocidade;
	posicoes[1].y = posicoes[1].y + velocidade;
	if (posicoes[0].y == gJanela.getAltura() / 2)
		posicoes[1].y = gJanela.getAltura() / 2 - gJanela.getAltura();
	if (posicoes[1].y == gJanela.getAltura() / 2)
		posicoes[0].y = gJanela.getAltura() / 2 - gJanela.getAltura();
}
