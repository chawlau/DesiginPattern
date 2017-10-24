/*
 *  Strategy
 */ 
#include <iostream>
#include <string>
using namespace std;

//抽象接口  
class ReplaceAlgorithm  
{  
public:  
    virtual void Replace() = 0;  
};  
//三种具体的替换算法  
class LRU_ReplaceAlgorithm : public ReplaceAlgorithm  
{  
public:  
    void Replace() { cout<<"Least Recently Used replace algorithm"<<endl; }  
};  
    
class FIFO_ReplaceAlgorithm : public ReplaceAlgorithm  
{  
public:  
    void Replace() { cout<<"First in First out replace algorithm"<<endl; }  
};  
class Random_ReplaceAlgorithm: public ReplaceAlgorithm  
{  
public:  
    void Replace() { cout<<"Random replace algorithm"<<endl; }  
};  

class Strategy
{
private:
    ReplaceAlgorithm *algorithm;
public:
    Strategy(ReplaceAlgorithm *r):algorithm(r){}
    void replace()
    {
        if(algorithm)
        {
            algorithm->Replace();
        }
    }
};