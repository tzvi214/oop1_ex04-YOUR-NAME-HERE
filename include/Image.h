#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include <string>

class Image
{
public:
	Image(const std::string&, const sf::Vector2f&);
	sf::Vector2f getPosition() const { return m_position; }
	std::string getName() const { return m_name ; }
private:
	sf::Vector2f m_position;
	std::string m_name;
};