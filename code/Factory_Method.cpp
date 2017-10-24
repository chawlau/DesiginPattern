/*
 *Factory Method
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

class Factory
{
public:
	virtual vehicle* create() = 0;
};

class FactoryCar :public Factory
{
public:
	vehicle* create()
	{
		return new car();
	}
};

class FactoryTruck :public Factory
{
public:
	vehicle* create()
	{
		return new truck();
	}
};