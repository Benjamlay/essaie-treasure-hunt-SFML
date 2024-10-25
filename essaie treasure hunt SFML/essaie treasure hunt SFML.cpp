#include <array>
#include <iostream>
#include "map.h"
#include "SFML/Graphics.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(256, 256), "treasure hunt");
	std::srand(time(0));
	static std::array<char, kRowSize* kColSize> map;
	map.fill('#');
	

	int idx_treasure = rand() % (kRowSize * kColSize);
	int idx_player;
	int round = 0;

	bool Too_much_Round = false;
	bool treasure_found = false;
	bool gameOver = false;

	sf::Clock clock;
	sf::Clock clockEndGame;
	sf::Time endGameDelay = sf::seconds(3);
	const sf::Time clocktime = sf::milliseconds(600);

	sf::Texture texturesize;
	texturesize.loadFromFile("asset\\sable.png");
	while(window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}
		show_map(window, map);
		if (event.type == sf::Event::MouseButtonReleased && clock.getElapsedTime() > clocktime)
		{
			clock.restart();
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				idx_player = convert_to_index(event.mouseButton.x / texturesize.getSize().x, event.mouseButton.y / texturesize.getSize().y);
				std::cout << idx_player << std::endl;
				if(idx_player >= 0 && idx_player < map.size())
				{
					map[idx_player] = '&';
					round++;
					if(round >= 7) // nombre de round
					{
						window.display();
						Too_much_Round = true;
						continue;
					}
				}
				else
				{
					std::cout << "nop" << '\n';
				}
				if(idx_player == idx_treasure)
				{
					map[idx_player] = '$';
					window.display();
					treasure_found = true;
					continue;
				}
				
			}
		}
		if (treasure_found || Too_much_Round)
		{
			gameOver = true;
		}

		if (gameOver)
		{
			break;
		}
		window.display();

	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

		}

		window.display();
	}

	std::cout << "end" << '\n';
	
	
	return 0;

	
}

