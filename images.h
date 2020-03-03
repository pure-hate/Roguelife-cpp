#pragma once
#include <SFML/Graphics.hpp>//вроде не обязательно, протестировать
using namespace sf;

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

static class Sprites {
public:
    void load()
    {
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