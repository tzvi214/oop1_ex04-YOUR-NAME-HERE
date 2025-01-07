#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include <string>
//#include <iostream>
class Image
{
public:
	Image(const std::string&, const sf::Vector2f&);
	sf::Vector2f getPosition() const;
	std::string getString() const { return m_name ; }
private:
	sf::Vector2f m_position;
	std::string m_name;
};