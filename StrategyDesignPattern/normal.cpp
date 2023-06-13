#include <iostream>

// base class
class Vehicle
{
public:
    void drive()
    {
        std::cout << "normal drive mode\n";
    }
};

// bus
class bus : public Vehicle
{
public:
    void drive()
    {
    }
};

// car
class car : public Vehicle
{
public:
    void drive()
    {
        std::cout << "boost drive mode\n";
    }
};

// bike
class bike : public Vehicle
{
public:
    void drive()
    {
        std::cout << "boost drive mode\n";
    }
};

// Problem here is :
// 1. bike and car boost mode implementation is same (duplicity)