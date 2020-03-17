#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <list>
#include <unordered_map>
#include "images.h"
#include "map.h"
#include "findpath.h"
#include "json.hpp"
#include "date.h"

using namespace sf;
using namespace std;
using namespace json;

RenderWindow window(VideoMode(640, 480), "RogueLife");
sf::View view(sf::FloatRect(0, 0, 640.f, 480.f));



#include "components.h"
#include "save.h"

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
FPS fps;

template <int row, int col>
void draw_map(int (&arr)[row][col])
{
    for (int i = 0; i < SIZEX; i++) //переключение по строкам
    {
        for (int j = 0; j < SIZEY; j++)// переключение по столбцам
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
    //шрифты
    Font font;
    font.loadFromFile("CyrilicOld.ttf");

    Text text("", font, 20);
    text.setFillColor(Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    
    Text text2("", font, 20);
    text2.setFillColor(Color::Red);
    text2.setStyle(sf::Text::Bold | sf::Text::Underlined);

    //спрайты
    Sprites allsprite;
    allsprite.load();

    window.setFramerateLimit(4);
    Components c;

    EntityID newID = 1;
    c.positions[newID] = Position{ 4, 4 };
    c.healths[newID] = Health{ 100, 100 };
    c.states[newID] = State{ "Idle" };
    c.names[newID] = Name{ "Вася" };
    c.main_sprites[newID] = Main_Sprite{ "playerSprite" };
    c.moneys[newID] = Money{ 100 };
    c.moneys[newID].AddMoney(20);

    c.inventories[newID] = Inventory{};
    c.inventories[newID].Add("Beer", pair("Marka", "Zhiguli"));
    c.inventories[newID].Add("Beer", pair("Marka", "Zhiguli"));
    c.inventories[newID].Add("Beer", pair("Marka", "Zhiguli"));

    int player = 1;
    

    newID = 2;
    c.positions[newID] = Position{ 1, 1 };
    c.healths[newID] = Health{ 100, 100 };
    c.main_sprites [ newID ] = Main_Sprite{ "humanSprite" };

    newID = 3;
    c.positions[newID] = Position{ 2, 2 };
    c.healths[newID] = Health{ 100, 100 };
    c.main_sprites[newID] = Main_Sprite{ "humanSprite" };

    c.traders[newID] = Trader{ "grocery" };
    c.states[newID] = State{ "Idle2" };
    c.names[newID] = Name{ "Вася" };
    c.moneys[newID] = Money{ 100 };
    

    c.inventories[newID] = Inventory{};
    c.inventories[newID].Add("Beer", pair("Marka", "Zhiguli"));


    Point i; i.x = 4; i.y = 4;                
    c.paths[newID].path.push_back(i);//добавляем точку в paths
    i.x = 3; i.y = 3;
    c.paths[newID].path.push_back(i);
    i.x = 2; i.y = 2;                
    c.paths[newID].path.push_back(i);
    
    Date current_date = { 0,0,1,1,2000 };

 
    loadmap();

    view.setViewport(sf::FloatRect(0, 0, 1, 1));
    
    
//главный цикл
    while (window.isOpen()) 
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        //движение персонажа с ид1
        if (Keyboard::isKeyPressed(Keyboard::Down)) 
        {
            if (global_map[c.positions[player].x][c.positions[player].y + 1] == 0) 
            { 
                c.positions[player].y += 1;
                view.setCenter(c.positions[player].x * 16, c.positions[player].y * 16);
                window.setView(view);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) 
        {
            if (global_map[c.positions[player].x][c.positions[player].y - 1] == 0)
            {
                c.positions[player].y -= 1;
                view.setCenter(c.positions[player].x * 16, c.positions[player].y * 16);
                window.setView(view);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) { 
            if (global_map[c.positions[player].x - 1][c.positions[player].y] == 0)
            {
                c.positions[player].x -= 1;
                view.setCenter(c.positions[player].x * 16, c.positions[player].y * 16);
                window.setView(view);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) { 
            if (global_map[c.positions[player].x + 1][c.positions[player].y] == 0)
            {
                c.positions[player].x += 1;
                view.setCenter(c.positions[player].x * 16, c.positions[player].y * 16);
                window.setView(view);
            }
        }

        

        //пробуем реализовать сохранения
        if (Keyboard::isKeyPressed(Keyboard::F6)) 
        { 

            Components& c_ptr = c;
            save(c_ptr);

        }

        //загрузка
        if (Keyboard::isKeyPressed(Keyboard::F7))
           
        {
            Components& c_ptr = c;
            load(c_ptr);
           
        }

        if (Keyboard::isKeyPressed(Keyboard::F1)) //пиво накидываем при нажатии
        {
            c.inventories[player].Add("Beer", pair("Marka", "Zhiguli"));  
        }
        
        //очистим экран перед отрисовкой
        
        
        
        

        window.clear();

        //рисуем сначала карту
        draw_map(global_map);

        current_date.increase();
        current_date.get_time();
        //проделывание одной и той же операции со всем списком

        for (auto& item : c.traders)
        {   
            if (c.paths[item.first].path.empty() == false)
            {
                int& x = c.positions[item.first].x;
                int& y = c.positions[item.first].y;
                vector<Point>& path = c.paths[item.first].path;

                x = path[0].x;
                y = path[0].y;
                
                //cout << x << " " << y << " " << path[0].x << " " << path[0].y;
                
                path.erase(path.begin());

                
                
            }
            else if (c.paths[item.first].path.empty() == true)
            {
                
                if (c.states[item.first].state == "Idle"s)
                {
                    
                    vector<Point>& new_path = c.paths[item.first].path;
                    c.states[item.first] = State{ "Idle2" };
                    SearchWay(global_map, new_path, c.positions[item.first].x, c.positions[item.first].y, 15, 10);
               
                }
                else if (c.states[item.first].state == "Idle2"s)
                {
                    vector<Point>& new_path = c.paths[item.first].path;
                    
                    SearchWay(global_map, new_path , c.positions[item.first].x, c.positions[item.first].y, 1, 1);
                    c.states[item.first] = State{ "Idle" };
                }

            }
        }

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

        c.moneys[player].DrawMoney();
        c.inventories[player].DrawInv();
        
        

        //и наконец выведем все на экран
        window.display();

        //счетчик фепеса
        fps.update();
        string str = to_string(fps.getFPS());
        window.setTitle(str);
        
        //std::cout << __cplusplus;

    }
    return 0;
}