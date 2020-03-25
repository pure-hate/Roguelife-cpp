#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <unordered_map>
#include "images.h"
#include "map.h"
#include "findpath.h"
#include "json.hpp"
#include "date.h"
#include "Constants.h"

using namespace sf;
using namespace std;
using namespace json;

RenderWindow window(VideoMode(640, 480), "RogueLife");
sf::View view(sf::FloatRect(0, 0, 640.f, 480.f));

#include "DrawMap.h"
#include "components.h"
#include "save.h"
#include "fps.h"
#include "Update.h"




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

    window.setFramerateLimit(MAXFPS);

    Components c;
    Components& c_ptr = c;

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
    c.inventories[newID].Add("Beer", pair("Marka", "Zhiguli2"));
    c.inventories[newID].Add("Beer", pair("Marka", "Zhiguli3"));

    int id = c.inventories[newID].Find("Beer");
    c.inventories[newID].Set(id, "Name", "beer23");
    c.inventories[newID].Set(id, "Volume", 500);



    int player = 1;
    int& player_ptr = player;
    

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
    Date& date_ptr = current_date;
    

 
    loadmap();

    view.setViewport(sf::FloatRect(0, 0, 1, 1));
   
    
    
//главный цикл
    while (window.isOpen()) 
    {
        Update(c_ptr, date_ptr, player_ptr);
    }

    return 0;
}