#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Observer
{
public:
     Observer() {};
     ~Observer() {};
     virtual void Update() = 0;
};


class Subject
{
public:
    Subject() {};
    virtual ~Subject() {};
    void Attach (Observer* o)
    {
         _observers.push_back(o);
    }

    void Detach (Observer* o)
    {
         int count = _observers.size();
         int i;

         for (i = 0; i < count; i++) {
           if(_observers[i] == o)
           break;
         }
         if(i < count)
          _observers.erase(_observers.begin() + i);
    }

    void Notify ()
    {
         int count = _observers.size();

         for (int i = 0; i < count; i++)
           (_observers[i])->Update();
    }

private:
    vector<Observer*> _observers;
};

class ConcreteSubject : public Subject
{
public:
    int GetState()
    {
        return SubjectState;
    }

    void SetState(int newState)
    {
        SubjectState=newState;
        Notify();
    }
private:
    int SubjectState;
};

class ConcreteObserver: public Observer
{
private:
    ConcreteSubject * subject;
    string behaviour;
public:

    ConcreteObserver(string behaviour,ConcreteSubject * subject):subject(subject),behaviour(behaviour)
    {
        subject->Attach(this);
    }
    void Update() {
        cout<<behaviour<<subject->GetState()<<endl;
    }
};



int main(int argc, char* argv[])
{
    ConcreteSubject lambda;

    ConcreteObserver o1("gram",&lambda);
    ConcreteObserver o2("spiewam",&lambda);
    ConcreteObserver o3("gwizdam",&lambda);
    lambda.SetState(1);


    return 0;
}
