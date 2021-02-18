#pragma once
#include <iostream>
using namespace std;

struct roman 
{
    std::string value;
};

struct arabic 
{
    int value;
};

class Convertor 
{
public:
    arabic toArabic(roman t);
    roman toRoman(arabic t);

    bool check(roman& t);

    void print(arabic A);
    void print(roman R);
};
