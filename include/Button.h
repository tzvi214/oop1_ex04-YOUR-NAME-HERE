#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "TextureManager.h"
class Button
{
public:
	Button(sf::Texture&, sf::Vector2f, sf::Vector2f);// i need to delete this constructor
	void draw(sf::RenderWindow&) const;
	//sf::Texture getTexture() const { return m_texture; } // to delete this function
	sf::Sprite create() const;  

	// the new changes
	std::string getString() const { return m_name; }

	Button(std::string , sf::Vector2f, sf::Vector2f);
	sf::Texture getTexture() const;// to change this to sf::Texture& getTexture() const;

private:

	sf::Texture m_texture;
	sf::Vector2f m_positionStart;
	sf::Vector2f m_positionEnd;
	// the new changes
	TextureManager m_textureManager;
	std::string m_name;
};
