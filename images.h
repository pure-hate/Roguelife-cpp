#pragma once
#include <SFML/Graphics.hpp>//вроде не обязательно, протестировать
using namespace sf;

sf::Font font;
Text invText;
Text moneyText;

std::ostringstream PlayerInvString;

Image wallImage;
Texture wallTexture;
Sprite wallSprite;

Image grassImage;
Texture grassTexture;
Sprite grassSprite;

Image humanImage;
Texture humanTexture;
Sprite humanSprite;

Image playerImage;
Texture playerTexture;
Sprite playerSprite;

class Sprites {
public:
    void load()
    {
        
        font.loadFromFile("CyrilicOld.ttf");

        invText.setCharacterSize(20);
        invText.setFont(font);
        invText.setFillColor(Color::Red);
        invText.setStyle(sf::Text::Bold | sf::Text::Underlined);

        moneyText.setCharacterSize(20);
        moneyText.setFont(font);
        moneyText.setFillColor(Color::Red);
        moneyText.setStyle(sf::Text::Bold | sf::Text::Underlined);


        wallImage.loadFromFile("images/wall.png");
        wallTexture.loadFromImage(wallImage);
        wallSprite.setTexture(wallTexture);

        grassImage.loadFromFile("images/grass.png");
        grassTexture.loadFromImage(grassImage);
        grassSprite.setTexture(grassTexture);

        humanImage.loadFromFile("images/human.png");
        humanTexture.loadFromImage(humanImage);
        humanSprite.setTexture(humanTexture);

        playerImage.loadFromFile("images/player.png");
        playerTexture.loadFromImage(playerImage);
        playerSprite.setTexture(playerTexture);
 

    }

};