#include "GameWindow.h"

void GameWindow::handleNewClick(const sf::Vector2f& location, char c)
{
	if (itsRobot(c) && robotExist())
		return;
	else if (need2delete(c))
		deleteObject(location, c);
	else
		addObject(location, c);
}
//-------------------------------------
void GameWindow::deleteObject(const sf::Vector2f& location, char c)
{
	// the function can delete 2 or more object in one time
	for (auto i = size_t(0); i < m_textureVec.size(); i++)
	{
		if (m_textureVec.at(i).getGlobalBounds().contains(location))
		{
			m_textureVec.erase(m_textureVec.begin() +i);

			if (itsRobot(c))// i delete the robot
				m_robotExist = false;
		}
	}

}
//-------------------------------------
void GameWindow::addObject(const sf::Vector2f& location, char c)
{
	TextureManager textureManager;
	sf::Texture newTexture;
	newTexture = textureManager.getTexture(c);
	m_textureVec.push_back(creat(newTexture, location));
	
	if (itsRobot(c))
		m_robotExist = true;
}
//-------------------------------------
sf::Sprite GameWindow::creat(const sf::Texture& tex, const sf::Vector2f& location)
{
	return sf::Sprite();
}