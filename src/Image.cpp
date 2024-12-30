#include "Image.h"

Image::Image(const sf::Texture& texture, const sf::Vector2f& location)
	:m_texture{texture}, m_position{location}
{ }

sf::Sprite Image::getSprite() const
{
	auto newObject = sf::Sprite();
	newObject.setPosition(m_position);
	newObject.setTexture(m_texture);
	newObject.setScale(0.1f, 0.1f); 
	return newObject;
}
