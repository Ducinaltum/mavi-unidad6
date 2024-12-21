#include "Game.h"
#include "FastAndFurious.h"
#include "Space.h"
#include "Bounce.h"
using namespace std;

void Game::ProcessEvent(Event& evt)
{
	if(m_currentGame != NULL)
		m_currentGame->ProcessEvent(evt);
	if (evt.type == sf::Event::Closed)
	{
		pWnd->close();
	}
}

void Game::DrawGame()
{
	if (m_currentGame != NULL)
		m_currentGame->DrawGame();
}

void Game::UpdateGame(float dt)
{
	if (m_currentGame != NULL)
		m_currentGame->UpdateGame(dt);
}

void Game::ProcessCollisions()
{
	if (m_currentGame != NULL)
		m_currentGame->ProcessCollisions();
}

Game::Game(int alto, int ancho, string titulo)
{
	pWnd = new RenderWindow(sf::VideoMode(alto, ancho, 32), titulo);
	m_currentGame = new Bounce(pWnd);
}

Game::Game(){}

Game::~Game(void)
{
}

void Game::Go()
{
	/////Objeto para recibir eventos/////
	Event evt;
	while (pWnd->isOpen())
	{
		/////Procesar eventos/////
		while (pWnd->pollEvent(evt))
		{
			ProcessEvent(evt);
		}
		/////Procesar colisiones/////
		ProcessCollisions();
		/////Actualizar estados de objetos/////
		UpdateGame(0.1f);
		pWnd->clear();
		DrawGame();
		pWnd->display();
	}
}
