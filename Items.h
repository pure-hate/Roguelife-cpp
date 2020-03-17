#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map> 
//using namespace std::string_literals;



    class Item
    {


    public:

        std::unordered_map<std::string, int> values;
        std::unordered_map<std::string, std::string> strings;
        std::unordered_map<std::string, bool> bools;
        void set(std::string str, int integer)
        {
            values[str] = integer;
        }

        void set(std::string str, const char* str2)
        {
            strings[str] = str2;
        }

        void set(std::string str, bool boolean)
        {
            bools[str] = boolean;
        }

        void Beer()
        {

            set("Name", "Tuborg");
            set("Volume", 500);
            set("Open", true);

            std::cout << "Пиво создано!\n";
        }

        std::string getstr(const char* str)
        {
            return strings[str];
        }

        bool getbool(const char* str)
        {
            return bools[str];
        }

        int getint(const char* str)
        {
            return values[str];
        }




    };