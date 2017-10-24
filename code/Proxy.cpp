/*
 * Proxy.cpp
 */
#include <iostream>

class Node
{
protected:
    std::string _name;
public:
    Node(std::string name):_name(name){}
    virtual void display(){}
};

class Sprite:public Node
{
public:
    Sprite(std::string name):Node(name){}
    virtual void display()
    {
        std::cout<<"sprite display";
    }
};

class DisplayProxy:public Node
{
private:
    Sprite *_sprite;
public:
    DisplayProxy(std::string name):Node(name),_sprite(nullptr){}
    virtual void display()
    {
        if(_sprite == nullptr)
        {
            _sprite = new Sprite(Node::_name);
        }

        _sprite->display();
    }

};
/*
int main()
{
    Node *node = new DisplayProxy("ait");
    node->display();
    delete node;
}
*/
