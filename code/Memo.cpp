/*
 *  Memonoono
 */ 
#include <iostream>
#include <vector>
#include <string>

//备忘录类  
class Memono  
{  
public:  
    std::string _state;  
    Memono(std::string tmp)  
    {  
        _state = tmp;  
    }  
};  
    
class Person  
{  
public:  
    std::string _state;  
    Memono* create_Memono()  
    {  
        return new Memono(_state);  
    }  
    void setMemono(Memono* tmp)  
    {  
        _state = tmp->_state;  
    }  
    
    void show()  
    {  
        std::cout << "状态:" << _state.c_str() << std::endl;  
    }  
};  
    
class manager  
{  
public:  
    Memono* _Memono;  
};  
    
    
    
int main()  
{  
    Person* p = new Person;  
    p->_state = "sb";  
    p->show();  
    
    //保存原始状态  
    manager* m = new manager;  
    m->_Memono = p->create_Memono();  
    
    //修改状态  
    p->_state = "on";  
    p->show();  
    
    //恢复  
    p->setMemono(m->_Memono);  
    p->show();  
    
    system("pause");  
    return 0;  
}  