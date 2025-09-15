#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Piece
{
public:
	sf::Texture texture;
	sf::Sprite sprite;
	Piece();
	~Piece();
	void setPosition(float x, float y);
};

