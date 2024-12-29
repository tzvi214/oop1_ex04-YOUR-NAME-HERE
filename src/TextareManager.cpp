#include "TextureManager.h"
#include <iostream>

TextureManager::TextureManager()
{
    if (!m_guardTex.loadFromFile("guard.jpg"))
        std::cerr << "Failed to load guard.jpg\n";
    if (!m_doorTex.loadFromFile("door.jpg"))
        std::cerr << "Failed to load door.jpg\n";
    if (!m_wallTex.loadFromFile("wall.jpg"))
        std::cerr << "Failed to load wall.jpg\n";
    if (!m_robotTex.loadFromFile("robot.jpg"))
        std::cerr << "Failed to load robot.jpg\n";
    if (!m_bombTex.loadFromFile("bomb.jpg"))
        std::cerr << "Failed to load bomb.jpg\n";
    if (!m_clearPageTex.loadFromFile("clearPage.jpg"))
        std::cerr << "Failed to load clearPage.jpg\n";
    if (!m_saveTex.loadFromFile("save.jpeg"))
        std::cerr << "Failed to load save.jpeg\n";
    if (!m_eraserTex.loadFromFile("eraser.jpg"))
        std::cerr << "Failed to load eraser.jpg\n";
}

sf::Texture& TextureManager::getTexture(const char ch)
{
    switch (ch)
    {
    case '!': return m_guardTex;
    case 'D': return m_doorTex;
    case '/': return m_robotTex;
    case '#': return m_wallTex;
    case '@': return m_bombTex;
    case 'S': return m_saveTex;
    case 'C': return m_clearPageTex;
    case 'E': return m_eraserTex;
    }
    std::cerr << "getTexture: char not found\n";
    throw std::runtime_error("Texture not found");
}

char TextureManager::getChar(const sf::Texture& texture) const
{
    sf::Image inputImage = texture.copyToImage();

    if (compareImages(inputImage, m_guardTex.copyToImage())) return '!';
    if (compareImages(inputImage, m_doorTex.copyToImage())) return 'D';
    if (compareImages(inputImage, m_robotTex.copyToImage())) return '/';
    if (compareImages(inputImage, m_wallTex.copyToImage())) return '#';
    if (compareImages(inputImage, m_bombTex.copyToImage())) return '@';
    if (compareImages(inputImage, m_saveTex.copyToImage())) return 'S';
    if (compareImages(inputImage, m_clearPageTex.copyToImage())) return 'C';
    if (compareImages(inputImage, m_eraserTex.copyToImage())) return 'E';

    std::cerr << "getChar: Texture not found\n";
    return '\0'; // Return null character if not found
}

bool TextureManager::compareImages(const sf::Image& img1, const sf::Image& img2) const
{
    if (img1.getSize() != img2.getSize())
        return false;

    const sf::Uint8* pixels1 = img1.getPixelsPtr();
    const sf::Uint8* pixels2 = img2.getPixelsPtr();

    for (size_t i = 0; i < img1.getSize().x * img1.getSize().y * 4; ++i)
    {
        if (pixels1[i] != pixels2[i])
            return false;
    }

    return true;
}
