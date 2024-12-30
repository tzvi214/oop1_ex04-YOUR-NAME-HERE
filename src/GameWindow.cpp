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
	for (auto i = size_t(0); i < m_ImageVec.size(); i++)
	{
		if (m_ImageVec.at(i).getSprite().getGlobalBounds().contains(location))
		{
			m_ImageVec.erase(m_ImageVec.begin() +i);
			
			//if (itsRobot(m_ImageVec.at(i).getchar()))// the function nat working 
			//	m_robotExist = false;
		}
	}

}
//-------------------------------------
void GameWindow::addObject(const sf::Vector2f& location, char c)
{
	TextureManager textureManager;
	sf::Texture newTexture;
	newTexture = textureManager.getTexture(c);
	m_ImageVec.push_back(Image(newTexture, location));
	
	if (itsRobot(c))
		m_robotExist = true;
}
//-------------------------------------
void GameWindow::draw(sf::RenderWindow& window) const
{
	for (auto i = size_t(0); i < m_ImageVec.size(); i++)
	{
		window.draw(m_ImageVec.at(i).getSprite());
		
    }
}
//-------------------------------------
void GameWindow::clearing()
{
	// i need to call to some dtor to delete the mammary
	m_ImageVec.clear();
	m_robotExist = false;
}



//-------------------------------------