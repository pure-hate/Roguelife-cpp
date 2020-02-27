#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "images.h"

using namespace sf;
using std::cout;

RenderWindow window(VideoMode(200, 200), "SFML works!");

#include "HumanClass.h"





//static class Sprites {
//public:
//    void load()
//    {
//        wallImage.loadFromFile("images/wall.png");
//        wallTexture.loadFromImage(wallImage);
//        wallSprite.setTexture(wallTexture);
//
//        grassImage.loadFromFile("images/grass.png");
//        grassTexture.loadFromImage(grassImage);
//        grassSprite.setTexture(grassTexture);
//
//        humanImage.loadFromFile("images/human.png");
//        humanTexture.loadFromImage(humanImage);
//        humanSprite.setTexture(humanTexture);
//    }
//
//};

template <int row, int col>
void draw_map(int (&arr)[row][col])
{
    for (int i = 0; i < 5; i++) //переключение по строкам
    {
        for (int j = 0; j < 5; j++)// переключение по столбцам
        {
            if (arr[i][j] == 1)
            {
                wallSprite.setPosition(i * 16, j * 16);
                window.draw(wallSprite);
            }
            if (arr[i][j] == 0)
            {
                grassSprite.setPosition(i * 16, j * 16);
                window.draw(grassSprite);
            }

        }
    }

}

int main()
{
    
    Sprites allsprite;
    allsprite.load();

    Human trader;
    trader.x = 1;
    trader.y = 2;
    trader.sprite = humanSprite;

    Human trader2;
    trader2.x = 1;
    trader2.y = 3;
    trader2.sprite = humanSprite;

    std::list <Human> mlist;

    mlist.push_back(trader);
    mlist.push_back(trader2);


    int map[5][5] = { {1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1}, };
    
    CircleShape shape(50.f);
    shape.setFillColor(Color::Green);
    

    while (window.isOpen()) //главный цикл
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) { shape.move(-0.1, 0); } //первая координата Х отрицательна =>идём влево
        if (Keyboard::isKeyPressed(Keyboard::Right)) { shape.move(0.1, 0); } //первая координата Х положительна =>идём вправо
        if (Keyboard::isKeyPressed(Keyboard::Up)) { shape.move(0, -0.1); } //вторая координата (У) отрицательна =>идём вверх (вспоминаем из предыдущих уроков почему именно вверх, а не вниз)
        if (Keyboard::isKeyPressed(Keyboard::Down)) { shape.move(0, 0.1); } //вторая координата (У) положительна =>идём вниз (если не понятно почему именно вниз - смотрим предыдущие уроки)


        window.clear();
        
        draw_map(map);
        window.draw(shape);

        //отрисовка людей
        for (auto iter = mlist.begin(); iter != mlist.end(); iter++)
        {
            (*iter).draw();
        }


        window.display();
    }
    return 0;
}