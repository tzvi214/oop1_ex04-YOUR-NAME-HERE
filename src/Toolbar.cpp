#include "Toolbar.h"

ToolBar::ToolBar() : m_toolbarWidht(0), m_numButten(8) {}// 8 is the number of buttons in the toolbar

//---------------------------------------------------------
void ToolBar::updateVecButten()
{
	std::string nameFile = "Toolbar.txt";
	std::ifstream file(nameFile);

	if (!file.is_open()) {
		std::cerr << "Error: Unable to open the file!" << std::endl;
		return;
	}

	int counter = 0;
	char ch;
	
	unsigned int StartWidhtButtem;
	unsigned int endWidhtButtem;

	while (file.get(ch))
	{
		
		StartWidhtButtem = (m_toolbarWidht / m_numButten) * counter;
		endWidhtButtem = (m_toolbarWidht / m_numButten) * (counter + 1);
		Button button(m_textureManager.getString(ch), sf::Vector2f(StartWidhtButtem, 0.f), sf::Vector2f(endWidhtButtem, 0.f));
		m_buttensVec.push_back(button);

		counter++;
	}

	// Add buttons for 'E', 'S', and 'C'
	for (char specialChar : {'E', 'S', 'C'})
	{
		StartWidhtButtem = (m_toolbarWidht / m_numButten) * counter;
		endWidhtButtem = (m_toolbarWidht / m_numButten) * (counter + 1);
		Button button(m_textureManager.getString(specialChar), sf::Vector2f(StartWidhtButtem, 0.f), sf::Vector2f(endWidhtButtem, 0.f));
		m_buttensVec.push_back(button);
		counter++;
	}

}
//---------------------------------------------------------
void ToolBar::draw(sf::RenderWindow& window) const
{
	
  for (auto i = size_t(0); i < m_buttensVec.size(); ++i)
  {
  	m_buttensVec[i].draw(window);
  }
}
//---------------------------------------------------------
void ToolBar::setToolbarWidht(unsigned int toolbarWidht)
{
	m_toolbarWidht = toolbarWidht;
}
//---------------------------------------------------------
bool ToolBar::pressIntoolbar(const sf::Vector2f& location)
{
	if (location.x < 0 || location.x > m_toolbarWidht)
		return false;
	if (location.y < 0 || location.y > m_toolbarHeight)
		return false;

	return true;
}
//---------------------------------------------------------
char ToolBar::getCharPress(const sf::Vector2f& location)
{
	for (auto i = size_t(0); i < m_buttensVec.size(); i++)
	{
		if (m_buttensVec[i].createSprite().getGlobalBounds().contains(location))
		{
			return m_textureManager.getChar((m_buttensVec[i].getString()));
		}
	}

	return 0;// the default will be null
}
