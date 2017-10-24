/*
 *  Composite
 */ 
#include <iostream>
#include <vector>

class node  
{  
protected:  
    std::string _name;  
public:  
    node(std::string tmp) :_name(tmp){}  
    virtual void addNode(node*) = 0;  
    virtual void show(int depth = 0) = 0;  
};  
   
class leaf :public node  
{  
public:  
    leaf(std::string tmp) :node(tmp){}  
    virtual void addNode(node* tmp)  
    {  
       std::cout << "叶子无法添加组件\n";  
    }  
    virtual void show(int depth = 0)  
    {  
       std::string tmp = "";  
       for (int i = 0; i < depth; i++)  
       {  
           tmp += "-";  
       }  
   
       tmp += _name;  
       std::cout << tmp.c_str();  
    }  
};  
   
class root:public node  
{  
private:  
    std::vector<node*> _root;  
public:  
    root(std::string tmp) :node(tmp){}  
    void addNode(node* tmp)  
    {  
       _root.push_back(tmp);  
    }  
   
    void show(int depth = 0)  
    {  
       std::string tmp = "";  
       for (int i = 0; i < depth; i++)  
       {  
           tmp += "-";  
       }  
   
       tmp += _name;  
       std::cout << tmp.c_str();  
       std::vector<node*>::iterator it = _root.begin();  
       for (; it != _root.end(); it++)  
       { 
           (*it)->show(depth += 2);  
       }  
    }  
}; 

int main()
{
    node *tmp = new root("root");

    node *l1 = new leaf("leaf1");
    node *l2 = new leaf("leaf2");
    node *t = new root("tree");

    node *l3 = new leaf("leaf3");

    t->addNode(l3);

    tmp->addNode(l1);
    tmp->addNode(l2);
    tmp->addNode(t);

    tmp->show();

    delete tmp;
}