/*
 *  Brige
 */ 
#include <iostream>

//abstract
class Application
{
public:
    virtual void runApplication() = 0;      //implement
};

class LinuxApp:public Application
{
public:
    virtual void runApplication()
    {
        std::cout<<"run apache server on linux";
    }
};

class WindowsApp:public Application
{
public:
    virtual void runApplication()
    {
        std::cout<<"run apache server on Windwos";
    }
};

class OperateSystem
{
protected:
    Application *_app;
public:
    void setApplication(Application *app)
    {
        _app = app;
    }

    virtual void runApplication()
    {
        if(_app)
        {
            _app->runApplication();
        }
    }
};

class Windows:public OperateSystem
{
    //TODO:other logic code
};

class Linux: public OperateSystem
{
    //TODO:other logic code
};

/*
int main()
{
    Application *app = new WindowsApp();
    OperateSystem *sys = new Windows();

    sys->setApplication(app);
    sys->runApplication();

    delete app;
    delete sys;
}
*/