#pragma once
#include "fps.h"

FPS fps;

void Update(Components& c, Date& current_date, int& player)
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
    //current_date.get_time();
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

                SearchWay(global_map, new_path, c.positions[item.first].x, c.positions[item.first].y, 1, 1);
                c.states[item.first] = State{ "Idle" };
            }

        }
    }

    //отрисовка всех персонажей с main_sprites
    for (auto& item : c.main_sprites)
    {
        int& x = c.positions[item.first].x;
        int& y = c.positions[item.first].y;

        string& sprite = item.second.main_sprite1;
        if (sprite == "humanSprite")
        {
            humanSprite.setPosition(x * 16.f, y * 16.f);
            window.draw(humanSprite);
        }
        if (sprite == "playerSprite")
        {
            playerSprite.setPosition(x * 16.f, y * 16.f);
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