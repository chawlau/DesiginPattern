/*
 *  Command
 */
#include <iostream>
#include <vector>
class COOK  
{  
public:  
    void fish()  
    {  
       std::cout << "水煮鱼\n";  
    }  
    void tofu()  
    {  
       std::cout << "千叶豆腐\n";  
    }  
    void beaf()  
    {  
       std::cout << "牛肉\n";  
    }  
};  
   
class Command  
{  
protected:  
    COOK* cooker;  
public:  
    //可以修改厨师参数  
    Command(COOK* tmp)  
    {  
       cooker = tmp;  
    }  
   
    virtual void operate() = 0;  
};  
   
class fish :public Command  
{  
public:  
    fish(COOK* tmp) :Command(tmp){}  
    virtual void operate()  
    {  
       cooker->fish();  
    }  
};  
   
class beaf :public Command  
{  
public:  
    beaf(COOK* tmp) :Command(tmp){}  
    virtual void operate()  
    {  
       cooker->beaf();  
    }  
};  
   
class tofu :public Command  
{  
public:  
    tofu(COOK* tmp) :Command(tmp){}  
    virtual void operate()  
    {  
       cooker->tofu();  
    }  
};  
   
class waiter  
{  
protected:  
    std::vector<Command*> _list;  
public:  
    //点菜  
    void order(Command* tmp)  
    {  
       _list.push_back(tmp);  
       std::cout << "点菜成功\n";  
    }  
   
    void run()  
    {  
       std::vector<Command*>::iterator it = _list.begin();  
       while (it != _list.end())  
       {  
           (*it)->operate();  
           it++;  
       }  
    }  
};  

int main()
{
    waiter *w = new waiter();       //服务员
    COOK *c = new COOK();           //厨师

    tofu *t = new tofu(c);           
    beaf *b = new beaf(c);           

    w->order(t);                    ////点菜豆腐
    w->order(b);                    //点菜牛肉

    w->run();
}