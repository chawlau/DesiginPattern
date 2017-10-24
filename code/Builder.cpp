#include <iostream>

class Builder
{
public:
    virtual void buildEngine() = 0;
    virtual void buildBody() = 0;
    virtual void buildTires() = 0;
};

class TruckBuilder:public Builder
{
public:
    virtual void buildEngine()
    {
        std::cout<<"Truck engine";
    }

    virtual void buildBody()
    {
        std::cout<<"Truck body";
    }

    virtual void buildTires()
    {
        std::cout<<"Truck tires";
    }
};

class CarBuilder:public Builder
{
public:
    virtual void buildEngine()
    {
        std::cout<<"car engine";
    }

    virtual void buildBody()
    {
        std::cout<<"car body";
    }

    virtual void buildTires()
    {
        std::cout<<"car tires";
    }
};

class BuildControler
{
private:
    Builder *_builder;
public:
    BuildControler(Builder* builder):_builder(builder){}
    void create()
    {
        _builder->buildBody();
        _builder->buildEngine();
        _builder->buildTires();
    }
};


// int main()
// {
//     TruckBuilder builder;
//     BuildControler con(&builder);
//     con.create();
// }