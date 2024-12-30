#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
class Image
{
public:
	Image(const sf::Texture &, const sf::Vector2f &);
	sf::Sprite getSprite() const;
	char getchar()const;
private:
	sf::Texture m_texture;
	sf::Vector2f m_position;

};