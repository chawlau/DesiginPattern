/*
 * Abstract Factory 
 */
#include <iostream>

//»ùÀà
class vehicle
{
public:
	virtual void run() = 0;
};

class car :public vehicle
{
public:
	virtual void run()
	{
		std::cout << "car run" << std::endl;
	}
};

class truck :public vehicle
{
public:
	virtual void run()
	{
		std::cout << "truck run" << std::endl;
	}
};

class ship
{
public:
	virtual void sail() = 0;
};

class Vessel :public ship
{
public:
	virtual void sail()
	{
		std::cout << "vessel" << std::endl;
	}
};

class boat :public ship
{
public:
	virtual void sail()
	{
		std::cout << "boat" << std::endl;
	}
};

class Factory
{
public:
	virtual vehicle* createCar() = 0;
	virtual ship* createShip() = 0;
};

class FactorySmall :public Factory
{
public:
	vehicle* createCar()
	{
		return new car();
	}

	ship* createShip()
	{
		return new boat();
	}
};

class FactoryBig :public Factory
{
public:
	vehicle* createCar()
	{
		return new truck();
	}

	ship* createShip()
	{
		return new Vessel();
	}
};

