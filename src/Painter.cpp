#include "Painter.h"
#include <iostream>
#include <filesystem>
void Painter::run()
{

  unsigned int boardHeight = 0, boardWidth = 0;

  bool retFlag; // If the file exists but cannot be expanded.
  loadBoardDimensions(boardHeight, boardWidth, retFlag);
  if (retFlag) return;

  std::cout << "Final dimensions: Width = " << boardWidth << ", Height = " << boardHeight << "\n";


  unsigned int heightPixel = boardHeight * m_PixelSize;
  unsigned int widthPixel = boardWidth * m_PixelSize;
  m_toolBar.setToolbarWidht(widthPixel);
  m_toolBar.updateVecButten();

  // set size board for GamWindow.
  m_gameWindow.setRow(boardHeight);
  m_gameWindow.setCol(boardWidth);



  // create new window in the requested size
  auto window = sf::RenderWindow(sf::VideoMode(widthPixel, heightPixel + m_toolbarHeight), "SFML: Tolbar");


  while (window.isOpen())
  {
      sf::Event event;
      while (window.pollEvent(event))
      {
          // close window
          if (event.type == sf::Event::Closed)
          {
              window.close();
          }

          // action.
          if (event.type == sf::Event::MouseButtonReleased)
          {
              auto location = window.mapPixelToCoords(
                  { event.mouseButton.x, event.mouseButton.y });

              // if press into "Toolbar"
              if (m_toolBar.pressIntoolbar(location))
              {
                  handlePress(window, location);
              }
          }

          window.clear();
          m_toolBar.draw(window); // draw "Toolbar"
          m_gameWindow.draw(window); // draw "gameWindow"
          window.display();
      }

  }
}
//-----------------------------------
void Painter::loadBoardDimensions(unsigned int& boardHeight, unsigned int& boardWidth, bool& retFlag)
{
    retFlag = true;
    const std::string fileName = "board.txt";
    if (std::filesystem::exists(fileName))
    {
        std::cout << "The file '" << fileName << "' exists. Reading dimensions from the file...\n";

        std::ifstream file(fileName);
        if (file.is_open()) {
            file >> boardHeight; 
            file >> boardWidth;  
            file.close();

            std::cout << "Read dimensions: Width = " << boardWidth << ", Height = " << boardHeight << "\n";
        }
        else {
            std::cerr << "Failed to open the file '" << fileName << "'.\n";
            return exit(EXIT_FAILURE); 
        }
    }
    else {
        std::cout << "The file '" << fileName << "' does not exist.\n";
        std::cout << "Enter width and height\n";
        // First width, then height!
        std::cin >> boardWidth >> boardHeight;
    }
    retFlag = false;
}

//--------- private_function -------


void Painter::handlePress( sf::RenderWindow& window, sf::Vector2f& location)
{
    while (window.isOpen())
    {
        char c = m_toolBar.getCharPress(location);
        if (nedd2save(c))
        {
            std::cout << "saving... \n \n";
            return;
        }
        else if (need2clear(c))
        {
           // std::cout << "clearing... \n ";
            clearing();
            return;
        }
        else if (nedd2add(c))
        {
            AddingObjects(window, location, c);
        }
    }
     
}

bool Painter::nedd2add(char c) const
{
    return (c == '!' || c == '/' || c == 'D' || c == '@' || c == '#'|| c == 'E');
}

void Painter::AddingObjects(sf::RenderWindow& window, sf::Vector2f& location, char c)
{
    

   sf::Event event;
   while (window.waitEvent(event))
   {
       if (event.type == sf::Event::Closed)
       {
           window.close();
           return;
       }
       if (event.type == sf::Event::MouseButtonReleased)
       {
            location = window.mapPixelToCoords(
               { event.mouseButton.x, event.mouseButton.y });
           if (!m_toolBar.pressIntoolbar(location))
           {
               m_gameWindow.handleNewClick(location, c);

               window.clear();
               m_toolBar.draw(window);
               m_gameWindow.draw(window);
               window.display();
           }

           else if (m_toolBar.pressIntoolbar(location))
           {
               return;
           }
       }
       
       else
           continue; 
   }
}

   
