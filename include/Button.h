#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "TextureManager.h"
class Button
{
public:
	Button(std::string, sf::Vector2f, sf::Vector2f);
	void draw(sf::RenderWindow&) const;
	sf::Sprite createSprite() const;  
	std::string getString() const { return m_name; }
private:
	std::string m_name;
	sf::Vector2f m_positionStart;
	sf::Vector2f m_positionEnd;
	TextureManager m_textureManager;
	const sf::Texture& getTexture() const;
};
