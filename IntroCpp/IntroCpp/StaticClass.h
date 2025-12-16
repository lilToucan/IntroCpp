#pragma once

#include <iostream>
#include <string>
#include <vector>

class StaticClass
{
public:
    static int count;
    static float pi;

    StaticClass()
    {
        count++;

        std::cout << "count= " << count << "\n";
    }
    ~StaticClass()
    {}

    static int GetCount();
};


