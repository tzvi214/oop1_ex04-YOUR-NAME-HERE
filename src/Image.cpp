#include "Image.h"
#include <iostream>

//Image::Image(const sf::Texture& texture, const sf::Vector2f& location)
//	:m_texture{ texture }, m_position{ location }
//{
//	TextureManager textures;
//	m_char = textures.getChar(m_texture);
//	m_name = textures.getString(m_char);
//}
//-------------------------------------
//sf::Sprite Image::getSprite() const
//{
//	auto newObject = sf::Sprite();
//	newObject.setPosition(m_position);
//	newObject.setTexture(m_texture);
//	newObject.setScale(0.1f, 0.1f);
//	return newObject;
//}

//-------------------------------------

//sf::Texture Image::getTexture() const
//{
//	return m_texture;
//}
//-------------------------------------
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
sf::Sprite Image::getSprite() const
{
	auto newObject = sf::Sprite();
	newObject.setPosition(m_position);
	newObject.setTexture(getTexture());
	newObject.setScale(0.1f, 0.1f);
	return newObject;
	
}
//-------------------------------------
const sf::Texture& Image::getTexture() const 
{
	return m_textures.getTexture(m_name);
}
