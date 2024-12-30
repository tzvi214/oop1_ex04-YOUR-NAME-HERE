#pragma once
#include <SFML/Graphics.hpp>

class Image
{
public:
	sf::Sprite create() const;  

private:
	sf::Texture m_texture;
	sf::Vector2f m_position;

};