#include <bits/stdc++.h>
using namespace std;

// LISKOV SUBSTITUTION PRINCIPLE
// inheritance should not narrow down the capability of parent class

class Vehicle
{
public:
    virtual void blowHorn() = 0;
    virtual void blowSiren() = 0;
};

class Car : public Vehicle
{
public:
    void blowHorn()
    {
        cout << "Car horn goes..peeee..\n";
    }
    void blowSiren()
    { // here Car subclass is narrowing down the capabilities of Vehicle class
        throw exception();
    }
};

class Ambulance : public Vehicle
{
public:
    void blowHorn()
    {
        cout << "Ambulance horn goes..peeee..\n";
    }
    void blowSiren()
    {
        cout << "Ambulance goes tenuu..tenuu!\n";
    }
};

int main()
{

    vector<Vehicle*> vehicle;

    vehicle.push_back(new Ambulance());
    vehicle.push_back(new Car());

    for(auto &x:vehicle){
        x->blowSiren();
    }
    

    return 0;
}
