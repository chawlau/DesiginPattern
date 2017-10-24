/*
 *  Interrpter
 */
#include <iostream>
#include <string>

class context  
{  
public:  
    std::string _txt_rst;  
    std::string _txt_snd;  
};  
   
class interpreter  
{  
public:  
    virtual void run(context*) = 0;  
};  
   
class senior_inter :public interpreter  
{  
public:  
    virtual void run(context* tmp)  
    {  
       std::cout << tmp->_txt_rst.c_str() << "高级解释器\n";  
    }  
};  
   
class inferior_inter :public interpreter  
{  
public:  
    virtual void run(context* tmp)  
    {  
       std::cout << tmp->_txt_rst.c_str() << "次级解释器\n";  
    }  
};  