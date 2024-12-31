#include "GameWindow.h"

void GameWindow::setRow(unsigned int row)
{
	m_row = row;
}

void GameWindow::setCol(unsigned int col)
{
	m_col = col;
}

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
			m_ImageVec.erase(m_ImageVec.begin() + i);

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
	// i need to call to some d-tor to delete the mammary
	m_ImageVec.clear();
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
		addNew.m_row = image.getPosition().y / m_PixelSize;
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
	std::ofstream file(fileName); // ���� �� ����� ������
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