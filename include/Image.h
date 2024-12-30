#pragma once
#include <SFML/Graphics.hpp>

class Image
{
public:
	Image(const sf::Texture &, const sf::Vector2f &);
	sf::Sprite getSprite() const;
private:
	sf::Texture m_texture;
	sf::Vector2f m_position;

};