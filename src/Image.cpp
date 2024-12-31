#include "Image.h"

Image::Image(const sf::Texture& texture, const sf::Vector2f& location)
	:m_texture{ texture }, m_position{ location }
{
	TextureManager textures;
	m_char = textures.getChar(m_texture);
}

sf::Sprite Image::getSprite() const
{
	auto newObject = sf::Sprite();
	newObject.setPosition(m_position);
	newObject.setTexture(m_texture);
	newObject.setScale(0.1f, 0.1f);
	return newObject;
}

sf::Texture  Image::getTexture() const
{
	return m_texture;
}

sf::Vector2f Image::getPosition() const
{
	return m_position;
}