/*
 * Prototype 
 */

#include <iostream>

class Prototype
{
protected:
    std::string name;
public:
    Prototype(){}
    virtual void setName(std::string nam)
    {
        name = nam;
    }
    
    virtual Prototype* clone() = 0;
    virtual void show(){}

    virtual ~Prototype(){}
};

class PrototypeA:public Prototype
{
public:
    PrototypeA (std::string nam):name(nam){}
    PrototypeA(Prototype &p)
    {
        name = p.name;
    }

    Prototype* clone()
    {
        return new PrototypeA(*this);
    }

    virtual void show()
    {
        std::cout<<"Prototype A";
    }

    virtual void setName(std::string nam)
    {
        this->name = nam;
    }
};