#include <iostream>
#include <string>

class Person;  
//中介类  
class mediator  
{  
public:  
    virtual void send(std::string msg, Person* tmp) = 0;  
};  
    
//操作对象  
class Person  
{  
protected:  
    mediator* _mediator;  
public:  
    Person(mediator* tmp) :_mediator(tmp){}  
};  
    
class Renter :public Person  
{  
public:  
    Renter(mediator* tmp) :Person(tmp){}  
    void send(std::string msg)  
    {  
        _mediator->send(msg,this);  
    }  

    void notify(std::string msg)  
    {  
        std::cout << "租客获得了消息:" << msg.c_str() << std::endl;  
    }  
};  
    
class HouseProdiver :public Person  
{  
public:  
    HouseProdiver(mediator* tmp) :Person(tmp){}  
    void send(std::string msg)  
    {  
        _mediator->send(msg, this);  
    }  
    void notify(std::string msg)  
    {  
        std::cout << "房东获得了消息:" << msg.c_str() << std::endl;  
    }  
};  
    
class med :public mediator  
{  
public:  
    Renter* _Renter;  
    HouseProdiver* _HouseProdiver;  
public: 
    void setRenter(Renter *renter)
    {
        _Renter = renter;
    }
    void setHouseProdiver(HouseProdiver *prodiver)
    {
        _HouseProdiver = prodiver;
    }
    
    void send(std::string msg, Person* tmp)  
    {  
        if (tmp == _Renter)  
        {  
            _Renter->notify(msg);  
        }  
        else  
        {  
            _HouseProdiver->notify(msg);  
        }  
    }  
};  


int main()
{
    med *m = new med();
    Renter *r =  new Renter(m);
    HouseProdiver *h = new HouseProdiver(m);

    m->setRenter(r);
    m->setHouseProdiver(h);

    m->send("hellp",r);

    delete m;
    delete r;
    delete h;
}