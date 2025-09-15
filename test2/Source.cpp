//#include <SFML/Graphics.hpp>
#include "Piece.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    Piece piece;
	piece.sprite.setPosition({ 400.f, 400.f });
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Blue);
        window.draw(shape);
		window.draw(piece.sprite);
        window.display();
    }
}