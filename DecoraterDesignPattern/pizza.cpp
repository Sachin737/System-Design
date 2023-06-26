#include <iostream>
using namespace std;

class BasePizza
{
public:
    virtual int cost() = 0;
};

class FarmHouse : public BasePizza
{
public:
    int cost()
    {
        return 200;
    }
};

class Margherita : public BasePizza
{
public:
    int cost()
    {
        return 100;
    }
};

// #### TOPPINGS

class ToppingDecorator : public BasePizza
{
public:
    virtual int cost() = 0;
};

class ExtraCheese : public ToppingDecorator
{
    BasePizza *basePizza;

public:
    ExtraCheese(BasePizza *pizza)
    {
        this->basePizza = pizza;
    }

    int cost()
    {
        return basePizza->cost() + 20;
    }
};

class Mushroom : public ToppingDecorator
{
    BasePizza *basePizza;

public:
    Mushroom(BasePizza *pizza)
    {
        this->basePizza = pizza;
    }

    int cost()
    {
        return basePizza->cost() + 50;
    }
};

int main()
{

    // my Order : margherita + ExtraCheese

    BasePizza *myPizza = new ExtraCheese(new Margherita());

    cout << myPizza->cost() << "\n"; // 100+20=120

    // Now add Mushroom to it

    myPizza = new Mushroom(myPizza);
    
    cout << myPizza->cost() << "\n"; // 100+20+50=170

    // Wow, Isn't it awesome!

    return 0;
}
