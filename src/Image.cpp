#include "Image.h"

sf::Vector2f Image::getPosition() const
{
	return m_position;
}
//-------------------------------------
Image::Image(const std::string& name, const sf::Vector2f& location)
	:m_name { name }, m_position{ location }  
{ }

