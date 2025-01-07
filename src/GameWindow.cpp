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
	 if (need2delete(c))
		deleteObject(location, c);
	else
		addObject(location, c);
}
//-------------------------------------
void GameWindow::clearing()
{
	m_ImageVec.clear();
	m_SaveTxtVec.clear();
	m_robotExist = false;

}
//-------------------------------------
void GameWindow::setImageVec(const Image& image)
{
	if (itsRobot(m_textureManager.getChar(image.getName())))// if the image is robot
		m_robotExist = true;

	m_ImageVec.push_back(image);
}
//-------------------------------------
void GameWindow::draw(sf::RenderWindow& window) const
{
	drawTile(window);
	for (auto i = size_t(0); i < m_ImageVec.size(); i++)
	{
		m_textureManager.draw(window, m_ImageVec.at(i).getName(), m_ImageVec.at(i).getPosition());
	}
}
//-------------------------------------
void GameWindow::save()
{
	for (const auto& image : m_ImageVec)
	{
		SaveTXT addNew;
		addNew.m_col = image.getPosition().x / m_PixelSize;
		addNew.m_row = (image.getPosition().y - 150) / m_PixelSize;
		addNew.m_ch = m_textureManager.getChar(image.getName());
		m_SaveTxtVec.push_back(addNew);
	}

	write2file();
}
//--------------- private_function ---------------------
void GameWindow::deleteObject(const sf::Vector2f& location, char c)
{

	auto correctLocation = calculateCorrectLocation(location);

	for (auto i = size_t(0); i < m_ImageVec.size(); i++)
	{
		if (m_ImageVec.at(i).getPosition() == correctLocation)                                                                   
		{
			if (itsRobot(m_textureManager.getChar(m_ImageVec.at(i).getName())))
				m_robotExist = false;

			m_ImageVec.erase(m_ImageVec.begin() + i);
		}
	}
}
//-------------------------------------
void GameWindow::addObject(const sf::Vector2f& location, char c)
{

	deleteObject(location, c);// nat to pot two object in one place
  auto newLocation = calculateCorrectLocation(location) ; 

  std::string newObject = m_textureManager.getString(c);
 
  m_ImageVec.push_back(Image(newObject, newLocation));

  if(itsRobot(c))
 	m_robotExist = true;

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
		board.at(chTXT.m_row).at(chTXT.m_col) = chTXT.m_ch;
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
sf::Vector2f GameWindow::calculateCorrectLocation(const sf::Vector2f& location)
{
	int x = location.x / m_PixelSize;
	int y = location.y / m_PixelSize;
	x *= m_PixelSize;
	y *= m_PixelSize;
	return sf::Vector2f(x, y);
}
//-------------------------------------
void GameWindow::drawTile(sf::RenderWindow& window) const
{
   for (int i = 0; i < m_col; i++)
   {
   	 for (int j = 0; j < m_row; j++)
   	 {
   	    sf::Vector2f location;
   	 	location.x = i * m_PixelSize;
   	 	location.y = j * m_PixelSize + 150;// toolbar height
   	 	m_textureManager.draw(window, "tile", location);
   	 }
   }
}
