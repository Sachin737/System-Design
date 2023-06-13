#include <iostream>

// mode interface
class DriveMode
{
public:
    DriveMode() {}
    virtual ~DriveMode() {}

    virtual void drive() = 0;
};

// Drive mode 1
class NormalMode : public DriveMode
{
public:
    void drive()
    {
        std::cout << "Normal drive mode\n";
    }
};

// Drive mode 2
class BoostMode : public DriveMode
{
public:
    void drive()
    {
        std::cout << "Boost drive mode\n";
    }
};
// Similarly multiple modes can be defined

//  vehicle class,
class Vehicle
{
private:
    DriveMode *myModeObj; // So this statement make has-a relation with Mode Class 
                            // we are not bounding our driveMode to any particular mode
                            // instead it will be decided by object of vehicle class when it will 
                            // intialize. 

public:
    Vehicle(DriveMode *mode)
    {
        this->myModeObj = mode;
    }

    void drive()
    {
        myModeObj->drive();
    }
};

// car
class Car : public Vehicle
{
public:
    Car() : Vehicle(new BoostMode())
    {
    }
};

// Bus
class Bus : public Vehicle
{
public:
    Bus() : Vehicle(new NormalMode())
    {
    }
};

// Bike
class Bike : public Vehicle
{

public:
    Bike() : Vehicle(new BoostMode())
    {
    }
};

int main(void)
{

    Car c1;
    c1.drive();

    Bus b1;
    b1.drive();

    Bike bi1;
    bi1.drive();

    return 0;
}
