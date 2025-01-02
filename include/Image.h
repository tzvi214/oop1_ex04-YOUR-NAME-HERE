#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include <string>
class Image
{
public:
	//Image(const sf::Texture &, const sf::Vector2f &);
	//sf::Sprite getSprite() const;
	
	//sf::Texture getTexture() const;
	// to levee this functions
	char getchar() const { return m_char; }
	sf::Vector2f getPosition() const;
	    // the new function
	Image(const std::string&, const sf::Vector2f&);

	sf::Sprite getSprite() const;
	const sf::Texture& getTexture() const ;
	std::string getString() const { return m_name ; }
private:
	//sf::Texture m_texture;
	sf::Vector2f m_position;
	char m_char;
	std::string m_name;
	TextureManager m_textures;
};