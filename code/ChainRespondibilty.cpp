/*
 *  Chain of Respondibilty
 */ 
#include <iostream>
#include <string>

using namespace std;
//抽象管理者  
class Manager  
{  
protected:  
    Manager *_manager;  
    string _name;  
public:  
    Manager(Manager *manager, string name):_manager(manager), _name(name){}  
    virtual void DealWithRequest(string name, int num)  {}  
};  
//经理  
class CommonManager: public Manager  
{  
public:  
    CommonManager(Manager *manager, string name):Manager(manager,name) {}  
    void DealWithRequest(string name, int num)   
    {  
        if(num < 500) //经理职权之内  
        {  
            cout<<"经理"<<_name<<"批准"<<name<<"加薪"<<num<<"元"<<endl<<endl;  
        }  
        else  
        {  
            cout<<"经理"<<_name<<"无法处理，交由总监处理"<<endl;  
            _manager->DealWithRequest(name, num);  
        }  
    }  
};  
//总监  
class Majordomo: public Manager  
{  
public:  
    Majordomo(Manager *manager, string name):Manager(manager,name) {}  
    void DealWithRequest(string name, int num)   
    {  
        if(num < 1000) //总监职权之内  
        {  
            cout<<"总监"<<_name<<"批准"<<name<<"加薪"<<num<<"元"<<endl<<endl;  
        }  
        else  
        {  
            cout<<"总监"<<_name<<"无法处理，交由总经理处理"<<endl;  
            _manager->DealWithRequest(name, num);  
        }  
    }  
};  
//总经理  
class GeneralManager: public Manager  
{  
public:  
    GeneralManager(Manager *manager, string name):Manager(manager,name) {}  
    void DealWithRequest(string name, int num)  //总经理可以处理所有请求  
    {  
        cout<<"总经理"<<_name<<"批准"<<name<<"加薪"<<num<<"元"<<endl<<endl;  
    }  
};  

int main()  
{     
    Manager *general = new GeneralManager(NULL, "A"); //设置上级，总经理没有上级  
    Manager *majordomo = new Majordomo(general, "B"); //设置上级  
    Manager *common = new CommonManager(majordomo, "C"); //设置上级  
    common->DealWithRequest("D",300);   //员工D要求加薪  
    common->DealWithRequest("E", 600);  
    common->DealWithRequest("F", 1000);  
    delete common; delete majordomo; delete general;  
    return 0;  
}  