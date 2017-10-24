/*
 * Simple Factory 
 */
#include <iostream>

//基类
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

enum vehicle_type
{
	CAR,TRUCK
};

//工厂类
class Factory
{
public:
	vehicle* create(vehicle_type type)
	{
		switch (type)
		{
		case CAR:
			return new car();
			break;
		case TRUCK:
			return new truck();
			break;
		default:
			break;
		}
	}
};