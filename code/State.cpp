/*
 * State
 */
#include <iostream>

class Work;  
class State  
{  
public:  
    virtual void doSomething(Work*) = 0;  
};  
   
class Work  
{  
private:  
    State* _state;  
public:  
    double hour;  
public:  
    Work()  
    {  
       _state = NULL;  
    }  
   
    void set_state(State* tmp)  
    {  
       if (_state)  
       {  
           delete _state;  
           _state = NULL;  
       }  
   
       _state = tmp;  
    }  
   
    void run()  
    {  
       _state->doSomething(this);  
    }  
   
};  
   
class night :public State  
{  
public:  
    virtual void doSomething(Work* w)  
    {  
       std::cout << "睡觉!\n";  
    }  
};  
   
class morning :public State  
{  
public:  
    virtual void doSomething(Work* w)  
    {  
       std::cout << "起床!\n";  
    }  
};  
   
class noon :public State  
{  
public:  
    virtual void doSomething(Work* w)  
    {  
       std::cout << "上班!\n";  
    }  
};  

int main()
{
    Work *work = new Work();
    noon *n = new noon();
    morning *m = new morning();

    work->set_state(n);
    work->run();
    work->set_state(m);
    work->run();

    delete work;
    delete n;
    delete m;
}