#include <iostream>
#include <vector>
using namespace std;

class Object
{
public:
    virtual std::string whatAmI()=0;
    virtual std::string toString()=0;
    virtual Object* clone()=0;
    virtual ~Object()
    {}
};

class IntObject: public Object
{
    int value;
public:
    IntObject(int v)
    {
        value=v;
    }
    virtual std::string whatAmI()
    {
        return("int");
    }
    virtual std::string toString()
    {
        return to_string(value);
    }
    virtual Object* clone()
    {
        return new IntObject(*this);
    }

};

class DoubleObject: public Object
{
    double value;
public:
    DoubleObject(double v)
    {
        value=v;
    }
    virtual std::string whatAmI()
    {
        return("double");
    }
    virtual std::string toString()
    {
        return to_string(value);
    }
    virtual Object* clone()
    {
        return new DoubleObject(*this);
    }
};

int main()
{
    IntObject p(1);
    DoubleObject p2(2);

    Object *wsk;
    wsk=&p2;

    Object *wsk2=wsk -> clone();

    cout<<wsk -> whatAmI()<<endl;
    cout<<wsk -> toString()<<endl;
    cout<<wsk -> clone()<<endl;

    wsk=&p;
    cout<<wsk -> whatAmI()<<endl;
    cout<<wsk -> toString()<<endl;
    cout<<wsk2 -> toString()<<endl;

    vector<Object*> objects;
    objects.push_back(new IntObject(3));


    for(auto &i: objects)
        cout<<i -> whatAmI()<<endl;
    return 0;
}
