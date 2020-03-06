#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <list>
#include <unordered_map>
#include "images.h"
#include "map.h"


using namespace sf;
using namespace std;

RenderWindow window(VideoMode(200, 200), "RogueLife");


#include "components.h"

class FPS
{
public:
    
    FPS() : mFrame(0), mFps(0) {}

    


    
    const unsigned int getFPS() const { return mFps; }

private:
    unsigned int mFrame;
    unsigned int mFps;
    sf::Clock mClock;

public:
    void update()
    {
        if (mClock.getElapsedTime().asSeconds() >= 1.f)
        {
            mFps = mFrame;
            mFrame = 0;
            mClock.restart();
        }

        ++mFrame;
    }
};
//FPS fps;




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

    window.setFramerateLimit(30);
    Components c;

    EntityID newID = 1;
    c.positions[newID] = Position{ 4, 4 };
    c.healths[newID] = Health{ 100, 100 };
    c.main_sprites[newID] = Main_Sprite{ "playerSprite" };
    int player = 1;
    

    newID = 2;
    c.positions[newID] = Position{ 1, 1 };
    c.healths[newID] = Health{ 100, 100 };
    c.main_sprites [ newID ] = Main_Sprite{ "humanSprite" };

    newID = 3;
    c.positions[newID] = Position{ 2, 2 };
    c.healths[newID] = Health{ 100, 100 };
    c.main_sprites[newID] = Main_Sprite{ "humanSprite" };

 
    loadmap();
    

    while (window.isOpen()) //главный цикл
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        //движение персонажа с ид1
        if (Keyboard::isKeyPressed(Keyboard::Down)) { c.positions[player].y += 1; }
        if (Keyboard::isKeyPressed(Keyboard::Up)) { c.positions[player].y -= 1; }
        if (Keyboard::isKeyPressed(Keyboard::Left)) { c.positions[player].x -= 1; }
        if (Keyboard::isKeyPressed(Keyboard::Right)) { c.positions[player].x += 1; }

        //пробуем реализовать сохранения

        if (Keyboard::isKeyPressed(Keyboard::F6)) 
        {
            ofstream outfile;
            outfile.open("Out.txt");
                outfile << "sprites" << endl;
                for (auto& item : c.main_sprites)
                {
                    outfile << item.first << " " << item.second.main_sprite1 << endl;
                }
                outfile << "positions" << endl;
                for (auto& item : c.positions)
                {
                    outfile << item.first << " " << item.second.x << " " << item.second.y << endl;
                }
                outfile << "healths" << endl;
                for (auto& item : c.healths)  
                {
                    outfile << item.first << " " << item.second.current << " " << item.second.max << endl;
                }
                outfile << "end" << endl;

                outfile.close();
            
            
        }

        if (Keyboard::isKeyPressed(Keyboard::F7))
        {
            ifstream f("Out.txt");

            string s;
            stringstream tempstring;
            getline(f, s);
            getline(f, s);
            
            
                while (s != "positions")
                {   
                    tempstring.clear();
                    tempstring << s;

                    std::string part1;
                    tempstring >> part1;

                    std::string part2;
                    tempstring >> part2;
                    
                    cout << "ID " << part1 << " Sprite " << part2 << endl;

                    getline(f, s);

                }
                getline(f, s);

                while (s != "healths")
                {
                    cout << s << endl;  
                    getline(f, s);
                }
                getline(f, s);

                while (s != "end")
                {
                    cout << s << endl;
                    getline(f, s);
                }
                getline(f, s);
                f.close();

        }
        //очистим экран перед отрисовкой
        window.clear();

        //рисуем сначала карту
        draw_map(global_map);

        //проделывание одной и той же операции со всем списком

        //отрисовка всех персонажей с main_sprites
        for (auto& item : c.main_sprites)
        {
            int &x = c.positions[item.first].x;
            int &y = c.positions[item.first].y;
            
            string &sprite = item.second.main_sprite1;
            if (sprite == "humanSprite")
            {
                humanSprite.setPosition(x * 16, y * 16);
                window.draw(humanSprite);
            }
            if (sprite == "playerSprite")
            {
                playerSprite.setPosition(x * 16, y * 16);
                window.draw(playerSprite);
            }

        }

        //и наконец выведем все на экран
        window.display();

        //счетчик фепеса
        //fps.update();
        //string str = to_string(fps.getFPS());
        //window.setTitle(str);
        


    }
    return 0;
}