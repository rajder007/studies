#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;


template <typename T>
class Vector
{
    std::vector<T> v;
    public:
    void push_back(const T& value)
    {
        v.push_back(value);
    }
    void pop_back()
    {
        v.pop_back();
    }
    auto operator[](const T& value)
    {
        return v.operator[](value);
    }
    auto size() const
    {
        return v.size();
    }
    T& front()
    {
        return v.front();
    }
    T& back()
    {
        return v.back();
    }
    auto begin()
    {
        return v.begin();
    }
    auto end()
    {
        return v.end();
    }
    void erase(size_t value)
    {
        v.erase(v.begin()+value);
    }
    void sort()
    {
        std::sort(v.begin(), v.end());
    }
    void push_front(const T& value)
    {
        v.insert(v.begin(), value);
    }

};
int main()
{
    Vector<int> n;
    for(int i=0;i<5;i++)
    {
        n.push_back(rand()%10);
    }
    for(const auto i: n)
        cout<<i<<", ";

    for(int i=0;i<5;i++)
    {
        n.push_front(rand()%10);
    }

    cout<<endl<<"front ";
    for(const auto i: n)
        cout<<i<<", ";

    n.sort();
    cout<<endl<<"posortowane ";
    for(const auto i: n)
        cout<<i<<", ";

    n.erase(2);

    return 0;
}
