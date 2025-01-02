#include "Button.h"

Button::Button(sf::Texture& texture, sf::Vector2f positionStart, sf::Vector2f positionEnd)
	:m_texture(texture), m_positionStart(positionStart), m_positionEnd(positionEnd)
{
	m_name = m_textureManager.getString(m_textureManager.getChar(m_texture));
}
//---------------------------------------------------------
void Button::draw(sf::RenderWindow& window) const
{
	window.draw(create());
}
//---------------------------------------------------------
sf::Sprite Button::create() const
{
	auto newObject = sf::Sprite();
	newObject.setPosition(m_positionStart);
	newObject.setTexture(m_texture);


	// Get the texture size
	auto textureSize = m_texture.getSize();

	// Calculate the scale factors based on the desired end position
	float scaleX = (m_positionEnd.x - m_positionStart.x) / textureSize.x;
	//float scaleY = (m_positionEnd.y - m_positionStart.y) / textureSize.y;

	// Set the scale
	newObject.setScale(scaleX, 1.0f);


	return newObject;
}
//---------------------------------------------------------
Button::Button(std::string name, sf::Vector2f positionStart, sf::Vector2f positionEnd)
	:m_positionStart(positionStart), m_positionEnd(positionEnd), m_name(name)
{ 
	m_texture = m_textureManager.getTexture(name);
}
//---------------------------------------------------------
sf::Texture Button::getTexture() const
{
	return m_textureManager.getTexture(m_name);
}
