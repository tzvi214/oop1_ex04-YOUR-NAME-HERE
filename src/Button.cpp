#include "Button.h"

Button::Button(std::string name, sf::Vector2f positionStart, sf::Vector2f positionEnd)
	: m_name(name), m_positionStart(positionStart), m_positionEnd(positionEnd)
{ }
//---------------------------------------------------------
void Button::draw(sf::RenderWindow& window) const
{
	window.draw(createSprite());
}
//---------------------------------------------------------
sf::Sprite Button::createSprite() const
{
	auto newObject = sf::Sprite();
	newObject.setPosition(m_positionStart);
	newObject.setTexture(getTexture());


	// Get the texture size
	auto textureSize = getTexture().getSize();

	// Calculate the scale factors based on the desired end position
	float scaleX = (m_positionEnd.x - m_positionStart.x) / textureSize.x;
	// Set the scale
	newObject.setScale(scaleX, 1.0f);
	return newObject;
}
//---------------------------------------------------------

const sf::Texture& Button::getTexture() const
{
	return m_textureManager.getTexture(m_name);
}
