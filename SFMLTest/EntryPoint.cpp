//////Bibliotecas//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"


using namespace sf;


int main() {
	Game game(800, 600, "Unidad 6");
	game.Go();
	return 0;
}