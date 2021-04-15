#include <iostream>
#include <cstring>
#include <string>

using namespace std;
using StringType= string;

struct Person
{
    StringType imie;
    StringType nazwisko;
    StringType zawod;

    Person(StringType i=" ", StringType n=" ", StringType z=" "):imie(i),nazwisko(n),zawod(z)
    {}
    StringType toString() const
    {
        return(imie+" "+nazwisko+" "+zawod);
    }
};
petla_for(StringType tekst)
{
    cout<<"zwykla: ";
    int rozmiar=tekst.size();
    for(int i=0; i<rozmiar; i++)
        cout<<tekst[i];
}

petla_zakresowa(StringType tekst)
{
    cout<<endl;
    cout<<"zakresowa: ";
    for(const auto &i: tekst)
        cout<<i;
}
iteratory(StringType tekst)
{
    cout<<endl;
    cout<<"iteratory: ";
    for(StringType::iterator i= tekst.begin(); i !=tekst.end(); i++)
        cout<<*i;
}

int main()
{
    const Person p1("Grzegorz","Braun","polityk");
    cout<<p1.toString()<<endl;
    StringType osoba=p1.toString();
    StringType &referencja =osoba;
    petla_for(osoba);
    petla_zakresowa(osoba);
    iteratory(osoba);
    return 0;
}
