#pragma once
#include <fstream>
#include <sstream>
#include <stdio.h>

#include "json.hpp"
#include "save.h"

using namespace std;
using namespace json;

void save(Components& c)
{

    json::JSON obj;

    for (auto& item : c.main_sprites)
    {

        obj[to_string(item.first)]["MainSprites"] = item.second.main_sprite1;
    }

    for (auto& item : c.states)
    {

        obj[to_string(item.first)]["State"] = item.second.Get();
    }
    int i = 1;
    for (auto& item : c.inventories)
    {
        for (auto& item2 : item.second.inv)
        {//������ � ������ �������� �������������
            for (auto& item3 : item2.bools)
            {
                obj[to_string(item.first)]["Inventory"][to_string(i)]["Bools"][item3.first] = item3.second;
            }
            for (auto& item3 : item2.values)
            {
                obj[to_string(item.first)]["Inventory"][to_string(i)]["Values"][item3.first] = item3.second;
            }
            for (auto& item3 : item2.strings)
            {
                obj[to_string(item.first)]["Inventory"][to_string(i)]["Strings"][item3.first] = item3.second;
            }
            i++;

        }
        i = 1;
    }

    for (auto& item : c.traders)
    {

        obj[to_string(item.first)]["Trader"] = item.second.type;
    }

    for (auto& item : c.names)
    {

        obj[to_string(item.first)]["Name"] = item.second.name;
    }

    for (auto& item : c.moneys)
    {

        obj[to_string(item.first)]["Money"] = item.second.amount;
    }



    for (auto& item : c.healths)
    {

        obj[to_string(item.first)]["Health"] = json::Array(item.second.current, item.second.max);
    }

    for (auto& item : c.positions)
    {

        obj[to_string(item.first)]["Position"] = json::Array(item.second.x, item.second.y);
    }



    for (auto& item : c.paths)
    {
        for (auto& elem : item.second.path)
        {
            obj[to_string(item.first)]["Path"].append(elem.x, elem.y);
        }

    }


    //save


    ofstream out;          // ����� ��� ������
    out.open("save.json"); // �������� ���� ��� ������
    if (out.is_open())
    {

        out << obj << std::endl;
    }
    out.close();
}



void load(Components& c)
{
    json::JSON obj;
    ifstream in("save.json", ios::in); // �������� ���� ��� ������

    string a;
    string line;
    while (getline(in, line))
    {
        a += line + "\n";
    }
    in.close();

    obj = JSON::Load(a);

    //cout << obj << " JSON";
    for (auto& j : obj.ObjectRange())
    {
        //j.first - ID ���������
        //std::cout << j.first << "\n"; 

        if (j.second.hasKey("MainSprites")) //��������� ������� ������
        {

            c.main_sprites[stoi(j.first)].main_sprite1 = obj[j.first]["MainSprites"].ToString();

        }

        if (j.second.hasKey("State")) //��������� ������� ������
        {
            c.states[stoi(j.first)].Set(obj[j.first]["State"].ToString());
           // c.states[stoi(j.first)] = State{ obj[j.first]["State"].ToString() };

        }

        if (j.second.hasKey("Name")) //��������� ������� ������
        {

            c.names[stoi(j.first)].name = obj[j.first]["Name"].ToString();

        }

        if (j.second.hasKey("Money")) //��������� ������� ������
        {

            c.moneys[stoi(j.first)].amount = obj[j.first]["Money"].ToInt();

        }



        if (j.second.hasKey("Trader")) //��������� ������� ������
        {

            c.traders[stoi(j.first)].type = obj[j.first]["Trader"].ToString();

        }

        if (j.second.hasKey("Inventory")) //��������� ������� ������
        {

            c.inventories[stoi(j.first)].inv.clear();
            for (auto& i : j.second["Inventory"].ObjectRange())
            {
                //���������� ������ �������
                //c.inventories[stoi(j.first)].Add("Beer", pair("Marka", "Zhiguli"));
                for (auto& k : i.second.ObjectRange())
                {
                    for (auto& l : k.second.ObjectRange())
                    {
                        //� ������ ��������
                        cout << l.first << " " << l.second << endl;
                    }
                }

                cout << endl << endl;
            }


        }


        if (j.second.hasKey("Health"))
        {
            c.healths[stoi(j.first)].current = obj[j.first]["Health"][0].ToInt();
            c.healths[stoi(j.first)].max = obj[j.first]["Health"][1].ToInt();
            //std::cout << j.second["Health"][0] << " " << j.second["Health"][1] << "\n";
        }

        if (j.second.hasKey("Position"))
        {
            c.positions[stoi(j.first)].x = obj[j.first]["Position"][0].ToInt();
            c.positions[stoi(j.first)].y = obj[j.first]["Position"][1].ToInt();
            //std::cout << j.second["Health"][0] << " " << j.second["Health"][1] << "\n";
        }





        if (j.second.hasKey("Path"))
        {
            c.paths[stoi(j.first)].path.clear();

            vector<int> s;
            Point b;

            for (auto& i : j.second["Path"].ArrayRange())
            {
                s.push_back(i.ToInt());
            }

            while (!s.empty())
            {
                b.x = s[0];
                s.erase(s.begin());
                b.y = s[0];
                s.erase(s.begin());
                c.paths[stoi(j.first)].path.push_back(b);
            }
        }

    }
}