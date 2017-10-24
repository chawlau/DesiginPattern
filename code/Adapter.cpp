/**
 * Adapter
 */
#include <iostream>

//类适配器
//需求
class Target
{
public:
    virtual void Request(){};
};

//现有接口
class Adaptee
{
public:
    void SpecificRequest()
    {
        std::cout<<"Called SpecificRequest()"<<std::endl;
    }
};

//适配
class Adapter : public Adaptee, public Target
{
public:
    void Request()
    {
        this->SpecificRequest();
    }
};

//对象适配器
class Target
{
public:
    virtual void Request(){};
};

class Adaptee
{
public:
    void SpecificRequest()
    {
    cout<<"Called SpecificRequest()"<<endl;
    }
};

class Adapter : public Target
{
private:
    Adaptee *adaptee;
public:
    Adapter()
    {
        adaptee = new Adaptee();
    }
    void Request()
    {
        adaptee->SpecificRequest();
    }
};