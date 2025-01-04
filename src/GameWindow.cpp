#include "GameWindow.h"

void GameWindow::setRow(unsigned int row)
{
	m_row = row;
}
//-------------------------------------
void GameWindow::setCol(unsigned int col)
{
	m_col = col;
}
//-------------------------------------
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
		if (m_ImageVec.at(i).createSprite().getGlobalBounds().contains(location))
		{
			if (itsRobot(m_ImageVec.at(i).getchar()))
				m_robotExist = false;

			m_ImageVec.erase(m_ImageVec.begin() + i);
	
		}
	}

}
//-------------------------------------
void GameWindow::addObject(const sf::Vector2f& location, char c)
{

	int x = location.x/m_PixelSize;
	int y = location.y /m_PixelSize;
	x *= m_PixelSize;
	y *= m_PixelSize;
	sf::Vector2f newLocation(x, y);

  TextureManager textureManager;
  std::string newObject = textureManager.getString(c);
 
  m_ImageVec.push_back(Image(newObject, newLocation));

  if(itsRobot(c))
 	m_robotExist = true;

}
//-------------------------------------
void GameWindow::draw(sf::RenderWindow& window) const
{
	TextureManager handleObject;
	drawTile(window);
	for (auto i = size_t(0); i < m_ImageVec.size(); i++)
	{
		//window.draw(m_ImageVec.at(i).createSprite());
		handleObject.draw(window, m_ImageVec.at(i).getString(), m_ImageVec.at(i).getPosition());
	}
}
//-------------------------------------
void GameWindow::clearing()
{
	m_ImageVec.clear();
	m_SaveTxtVec.clear();
	m_robotExist = false;

}
//-------------------------------------

void GameWindow::save()
{
	/*The truth is that the "IMAGE" class should do this part just for the sake of simplicity and to make it easier to debug. In the meantime, I wrote it here.*/
	for (const auto& image : m_ImageVec)
	{
		SaveTXT addNew;
		addNew.m_col = image.getPosition().x / m_PixelSize;
		addNew.m_row = (image.getPosition().y -150)/ m_PixelSize;
		addNew.m_ch = image.getchar();
		m_SaveTxtVec.push_back(addNew);
	}

	write2file();
}
//-------------------------------------

void GameWindow::write2file() const
{

	int numCols = m_col;
	int numRows = m_row;

	// Create an entire table filled with a blank character (' ')
	std::vector<std::vector<char>> board(numRows, std::vector<char>(numCols, ' '));

	for (const auto& chTXT : m_SaveTxtVec)
	{
		board[chTXT.m_row][chTXT.m_col] = chTXT.m_ch;
	}



	std::string fileName = "Board.txt";
	std::ofstream file(fileName); 
	if (!file) { std::cerr << "Failed to open file: " << fileName << std::endl; }
	else {
		file << m_row << std::endl << m_col << std::endl;
		//write the board to file
		for (int row = 0; row < numRows; ++row)
		{
			for (int col = 0; col < numCols; ++col)
			{
				file << board[row][col];
			}
			file << std::endl;
		}


		file.close();
	}
}
//-------------------------------------
void GameWindow::drawTile(sf::RenderWindow& window) const
{
	TextureManager textureManager;
	for (int i = 0; i < m_col; i++)
	{
		for (int j = 0; j < m_row; j++)
		{
			sf::Vector2f location;
			location.x = i * m_PixelSize;
			location.y = j * m_PixelSize + 150;// tolbar height
			textureManager.draw(window, "tile", location);
		}
	}
}