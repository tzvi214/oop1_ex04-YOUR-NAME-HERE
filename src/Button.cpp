#include "Button.h"



Button::Button(sf::Texture& texture, sf::Vector2f position) :m_texture(texture), m_position(position)
{
}

void Button::draw(sf::RenderWindow& window) const
{
	window.draw(create());
}

sf::Sprite Button::create() const
{
	auto newObject = sf::Sprite();
	newObject.setPosition(m_position);
	newObject.setTexture(m_texture);
	newObject.setScale(0.25, 0.25);
	return newObject;
}