#include "Piece.h"
Piece::Piece() : sprite(this->texture) {
	texture.loadFromFile("quanmaden.png");
	this->sprite = sf::Sprite(this->texture);
};
void Piece::setPosition(float x, float y) {
	sprite.setPosition({x,y});
};
Piece::~Piece() {};