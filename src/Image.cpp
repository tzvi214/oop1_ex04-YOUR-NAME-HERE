#include "Image.h"
#include <iostream>

sf::Vector2f Image::getPosition() const
{
	return m_position;
}
//-------------------------------------
Image::Image(const std::string& name, const sf::Vector2f& location)
	:m_name { name }, m_position{ location }  
{
	m_char = m_textures.getChar(m_name);
}
//-------------------------------------
sf::Sprite Image::createSprite() const
{
	auto newObject = sf::Sprite();
	newObject.setPosition(m_position);
	newObject.setTexture(getTexture());
	newObject.setScale(0.25f, 0.25f);
	return newObject;
	
}
//-------------------------------------
const sf::Texture& Image::getTexture() const 
{
	return m_textures.getTexture(m_name);
}
