/*
 *Flyweight
 */
#include <iostream>
#include <vector>

class web  
{  
protected:
    std::string _name;      //inner data
public:  
    web(std::string tmp):_name(tmp){}
    std::string getString()
    {
        return _name;
    }

    virtual void use() = 0;  
};  
   
class share_web :public web  
{    
public:  
    share_web(std::string tmp) :web(tmp)  
    {}  
   
    virtual void use()  
    {  
       std::cout << "共享网站\n";  
    }  
};  
   
class unshare_web :public web  
{   
public:  
    unshare_web(std::string tmp) :web(tmp)  
    {}  
   
    virtual void use()  
    {  
       std::cout << "不共享网站\n";  
    }  
};  
   
//网站工厂  
class web_fatory  
{  
private:  
    std::vector<web*> _web;  
public:  
    web_fatory()  
    {  
    }  

    web* getweb(std::string key)  
    {  
       auto it = _web.begin();
       for(;it != _web.end();it ++)
       {
            if((*it)->getString() == key)
            {
                return *it;
            }
       }

       _web.push_back(new share_web(key));
    }  

    ~web_fatory()
    {
        auto it = _web.begin();
        for(;it != _web.end();it ++)
        {
            delete *it;
        }
    }
}; 
