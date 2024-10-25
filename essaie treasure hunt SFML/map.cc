#include "map.h"



void show_map(sf::RenderWindow& window, std::array<char, kRowSize* kColSize> map)
{
	sf::Sprite sand;
	sf::Texture sandTexture;
	sandTexture.loadFromFile("asset\\sable.png");
	sand.setTexture(sandTexture);

	sf::Sprite Treasure;
	sf::Texture treasureTexture;
	treasureTexture.loadFromFile("asset\\treasure.png");
	Treasure.setTexture(treasureTexture);

	sf::Sprite grass;
	sf::Texture grassTexture;
	grassTexture.loadFromFile("asset\\grass.png");
	grass.setTexture(grassTexture);

	for (int x = 0; x < kRowSize; x++)
	{
		for (int y = 0; y < kColSize; y++)
		{
			int idx = convert_to_index(x, y);
			int step_x = (sandTexture.getSize().x + 2);
			if(map[idx] == '#')
			{
				sand.setPosition(x * step_x, y * step_x);
				window.draw(sand);
			}
			else if(map[idx] == '&')
			{
				grass.setPosition(x * step_x, y * step_x);
				window.draw(grass);
			}
			else if(map[idx] == '$')
			{
				Treasure.setPosition(x * step_x, y * step_x);
				window.draw(Treasure);
			}
		}
	}
}

int convert_to_index(int x, int y)
{
	return y * kColSize + x;
}
