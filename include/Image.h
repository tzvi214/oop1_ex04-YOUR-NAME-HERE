#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include <string>
class Image
{
public:
	Image(const std::string&, const sf::Vector2f&);
	char getchar() const { return m_char; }
	sf::Vector2f getPosition() const;
	sf::Sprite getSprite() const;
	std::string getString() const { return m_name ; }
private:
	sf::Vector2f m_position;
	char m_char;
	std::string m_name;
	TextureManager m_textures;
	const sf::Texture& getTexture() const;// to delet this function
};