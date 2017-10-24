/*
 *Facade
 */ 
#include <iostream>

class PerCompiler
{
public:
    void perCompile()
    {
        std::cout<<"预编译"<<std::endl;
    }
};

class Compiler
{
public:
    void compile()
    {
        std::cout<<"编译"<<std::endl;
    }
};

class Link
{
public:
    void link()
    {
        std::cout<<"链接"<<std::endl;
    }
};

class Comile
{
public:
    void run()
    {
        PerCompiler per;
        Compiler com;
        Link link;

        per.perCompile();
        com.compile();
        link.link();
    }
};

/*
int main()  
{  
    Compile compiler;  
    compile.run();  
    return 0;  
}  */