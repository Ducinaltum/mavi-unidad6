#include "Game.h"
#include "FastAndFurious.h"
#include "Space.h"
#include "Bounce.h"
#include "WildPhysics.h"
using namespace std;

void Game::ProcessEvent(Event& evt)
{
	if (m_currentGame != NULL)
		m_currentGame->ProcessEvent(evt);
	if (evt.type == sf::Event::Closed)
	{
		pWnd->close();

	}
	else if (evt.type == sf::Event::KeyPressed)
	{
		if (evt.key.code == sf::Keyboard::Num1)
		{
			delete m_currentGame;
			m_currentGame = new FastAndFurious(pWnd);
		}
		else if (evt.key.code == sf::Keyboard::Num2)
		{
			delete m_currentGame;
			m_currentGame = new Space(pWnd);
		}
		else if (evt.key.code == sf::Keyboard::Num3)
		{
			delete m_currentGame;
			m_currentGame = new Bounce(pWnd);
		}
		else if (evt.key.code == sf::Keyboard::Num4)
		{
			delete m_currentGame;
			m_currentGame = new WildPhysics(pWnd);
		}
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
	srand(NULL);
	clock.restart();
	pWnd = new RenderWindow(sf::VideoMode(alto, ancho, 32), titulo);
	m_currentGame = new FastAndFurious(pWnd);
}

Game::Game() {}

Game::~Game(void)
{
}

void Game::Go()
{
	/////Objeto para recibir eventos/////
	Event evt;
	while (pWnd->isOpen())
	{
		float dt = clock.getElapsedTime().asSeconds();
		clock.restart();
		/////Procesar eventos/////
		while (pWnd->pollEvent(evt))
		{
			ProcessEvent(evt);
		}
		/////Procesar colisiones/////
		ProcessCollisions();
		/////Actualizar estados de objetos/////
		UpdateGame(dt);
		pWnd->clear();
		DrawGame();
		pWnd->display();
	}
}
