/*
 *  Decorator
 */
#include <iostream>

class Mechine  
{  
private:  
    std::string _name;  
public:  
    Mechine(std::string tmp) :_name(tmp){}  
    Mechine(){}  
    virtual void show() = 0;
};  
    
class AirCondition:public Mechine
{
public:
    AirCondition(std::string name):Mechine(name){}
    AirCondition(){}
    virtual void show()
    {
        std::cout<<"机器的名称是" << _name.c_str();
    }
};

class Television:public Mechine
{
public:
    Television(std::string name):Mechine(name){}
    Television(){}
    virtual void show()
    {
        std::cout<<"机器的名称是" << _name.c_str();
    }
};

class Decorator:public Mechine  
{  
protected:  
    Mechine* _person;   //要进行装饰的类
public:  
    Decorate(Mechine* tmp)  
    {  
        _person = tmp;  
    }  

    virtual void show()  
    {  
        _person->show();  
    }  
};  
    
class AirDecorator :public Decorator  
{  
public:  
    AirDecorator(Mechine *tmp):Decorator(tmp){}
    virtual void show()  
    {  
        this->ExternalFunction();
        Decorator::show();  
    }  

    void ExternalFunction() //额外功能
    {
        //TODO:
    }
};  
    
class TeleDecorator :public Decorator  
{  
public:  
    TeleDecorator(Mechine *tmp):Decorator(tmp){}
    virtual void show()  
    {  
        this->ExternalFunction();
        Decorator::show();  
    }  

    void ExternalFunction() //额外功能
    {
        //TODO:
    }
};  

/*
int main()
{
    Mechine *air = new AirCondition("air");
    Decorator * dec = new TeleDecorator(air);

    dec->show();

    delete air;
    delete dec;
}*/