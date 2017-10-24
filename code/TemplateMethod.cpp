/*
 * Template Method
 */
#include <iostream>

//不同操作系统的中断处理
class OperateSystem
{
protected:
    virtual void TriggerInterrupt() = 0;        //触发中断
    virtual void SaveContext() = 0;             //保存现场
    virtual void InterruptSoulation() = 0;       //中断处理
    virtual void ReturnContext() = 0;           //返回现场
public:
    virtual void HandleInterrupt()
    {
        this->TriggerInterrupt();
        this->SaveContext();
        this->InterruptSoulation();
        this->ReturnContext();
    }
};

class Windows:public OperateSystem
{
private:
    virtual void TriggerInterrupt()        //触发中断
    {
        std::cout<<"Windows trriger\n";
    }

    virtual void SaveContext()             //保存现场
    {
        std::cout<<"Windows save context\n";
    }

    virtual void InterruptSoulation()       //中断处理
    {
        std::cout<<"Windows interrupt soulation\n";
    }

    virtual void ReturnContext()           //返回现场
    {
        std::cout<<"Windows return context\n";
    }
};

class Linux:public OperateSystem
{
private:
    virtual void TriggerInterrupt()        //触发中断
    {
        std::cout<<"Linux trriger\n";
    }

    virtual void SaveContext()             //保存现场
    {
        std::cout<<"Linux save context\n";
    }

    virtual void InterruptSoulation()       //中断处理
    {
        std::cout<<"Linux interrupt soulation\n";
    }

    virtual void ReturnContext()           //返回现场
    {
        std::cout<<"Linux return context\n";
    }
};

int main()
{
    Linux *linux = new Linux();
    Windows *window = new Windows();

    linux->HandleInterrupt();
    window->HandleInterrupt();
}