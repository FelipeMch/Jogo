#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(850, 800, false);
	
	gRecursos.carregarSpriteSheet("bJogar", "bin/assets/botoes/jogar.png", 3);
	botoes[bJogar].setSpriteSheet("bJogar");
	botoes[bJogar].setPos(gJanela.getLargura() / 2, 500);

	gRecursos.carregarSpriteSheet("bCreditos", "bin/assets/botoes/creditos.png", 3);
	botoes[bCreditos].setSpriteSheet("bCreditos");
	botoes[bCreditos].setPos(gJanela.getLargura() / 2, 550);

	gRecursos.carregarSpriteSheet("bInstrucoes", "bin/assets/botoes/instrucoes.png", 3);
	botoes[bInstrucoes].setSpriteSheet("bInstrucoes");
	botoes[bInstrucoes].setPos(gJanela.getLargura() / 2, 600);

	gRecursos.carregarSpriteSheet("bSair", "bin/assets/botoes/sair.png", 3);
	botoes[bSair].setSpriteSheet("bSair");
	botoes[bSair].setPos(gJanela.getLargura() / 2, 650);

	//gRecursos.carregarSpriteSheet("bOk", "bin/assets/botoes/bOk.png", 3);
	//botoes[bOk].setSpriteSheet("bOk");
	//botoes[bJogar].setPos(gJanela.getLargura() / 2, 400);

	//gRecursos.carregarSpriteSheet("bVoltar", "bin/assets/botoes/bVoltar.png", 3);
	//botoes[bVoltar].setSpriteSheet("bVoltar");
	//botoes[bJogar].setPos(gJanela.getLargura() / 2, 400);
	
	telaAtual = tInicial;

	fase.inicializar(&personagem); //& pega o endereço do personagem na memória

}

void Jogo::executar()
{
	while(telaAtual != tSaida && !gEventos.sair)
	{
		uniIniciarFrame();

		switch (telaAtual)
		{
			case tInicial: telaInicial();
					break;
		
			case tJogo: telaJogo();
				break;
		
			case tCreditos: telaCreditos();
				break;
		
			case tInstrucoes: telaInstrucoes();
				break;
		
			case tGameOver: telaGameOver();
				break;
		}

		uniTerminarFrame();
	}
}

void Jogo::finalizar()
{
	
	fase.finalizar();
	
	uniFinalizar();
}

void Jogo::telaInicial()
{
	botoes[bJogar].atualizar();
	botoes[bJogar].desenhar();
	if (botoes[bJogar].estaClicado())
	{
		telaAtual = tJogo;
	}

	botoes[bCreditos].atualizar();
	botoes[bCreditos].desenhar();
	if (botoes[bCreditos].estaClicado())
	{
		telaAtual = tCreditos;
	}

	botoes[bInstrucoes].atualizar();
	botoes[bInstrucoes].desenhar();
	if (botoes[bInstrucoes].estaClicado())
	{
		telaAtual = tInstrucoes;
	}

	botoes[bSair].atualizar();
	botoes[bSair].desenhar();
	if (botoes[bSair].estaClicado())
	{
		telaAtual = tSaida;
	}
}

void Jogo::telaJogo()
{
	fase.desenhar();
	fase.executar();
	if (personagem.getMorte() == false)
	{
		telaAtual = tGameOver;
	}

}

void Jogo::telaCreditos()
{
}

void Jogo::telaInstrucoes()
{
}

void Jogo::telaGameOver()
{
}
