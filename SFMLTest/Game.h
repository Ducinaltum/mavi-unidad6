#include <SFML/Window.hpp> 
#include <SFML/Graphics.hpp> 
#include <string>

using namespace std;
using namespace sf;

#pragma once
class Game
{
private:
	Game * m_currentGame;
	Clock clock;
protected:
	RenderWindow * pWnd;
	virtual void ProcessEvent(Event& evt);
	virtual void DrawGame();
	virtual void UpdateGame(float dt);
	virtual void ProcessCollisions();
public:
	Game(int alto, int ancho, string titulo);
	Game();
	~Game(void);
	virtual void Go();
};