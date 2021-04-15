#include <iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

//Deklaracja klasy listy dwukierunkowej
class lista{
public:
    class ogniwo{
    public:
        ogniwo * next;
        ogniwo * prev;
        string value;
};
    class interator: public iterator<forward_iterator_tag,string>
    {
    public:
        ogniwo * wsk;
        interator next(interator it);
        interator operator++()
        {
            *this=next(*this);
            return *this;
        }
        string& operator*()
        {
            return wsk->value;
        }
        bool operator!=(interator it) const
        {
            return wsk != it.wsk;
        }
};
    lista(string v);
    void wyswietl();
    interator insert_list(interator it, string v);
    interator delete_list(interator it);
    interator begin();
    interator end();
    interator get(string v);
    vector<string> toVector() const
    {
        vector<string> v,v2;
        interator it = poczatek;
        for(int i = 0 ; i < size ; i++){
            v.push_back(it.wsk->value);
            it.wsk = it.wsk->next;
        }
        std::copy(v.begin(),v.end(),back_inserter(v2));
        return v;
    }

    list<string> toList() const
    {
        list<string> v;
        interator it = poczatek;
        for(int i = 0 ; i < size ; i++){
            v.push_back(it.wsk->value);
            it.wsk = it.wsk->next;
        }
        return v;
    }

    interator poczatek;
    interator koniec;
    int size;
};

//Przyklad uzycia
int main()
{
    //uwtorz liste z elementem o wartosci 2
    lista L("ll");

    //pobierz wskaznik na pierwszy element listy
    lista::interator it = L.begin();

    //wstaw element 3, za pierwszym elementem
    L.insert_list(it,"ss");

    //przesun wskaznik na kolejny element
    it = it.next(it);

    //wstaw element o wartosci 8, za elementem o wartosci 3
    L.insert_list(it,"aa");

    //wstaw element o wartosci 12, za elementem o wartosci 3
    L.insert_list(it,"awds");

    //wyswietl zawartosc listy
    L.wyswietl();
    cout << "\n";

    //pobierz wskaznik na element o wartosci 8
    it = L.get("aa");
    cout << it.wsk->value << "\n";

    //usun element o wartosci 8 z listy
    L.delete_list(it);

    //wyswietl zawartosc listy
    L.wyswietl();
    cout << "\n";

    auto it2 = find (L.begin(), L.end(), "aa");
    if (it2 != L.end())
        cout << "Element found in myvector: " << *it2 << '\n';

    return 0;
}


//***************
// METODY
//***************

//Konstruktor listy
//tworzy nowa liste dwukierunkowa z jednym elementem o zadanej wartosci v
lista::lista(string v){
    ogniwo * a= new ogniwo;
    a->next = a;
    a->prev = a;
    a->value = v;
    poczatek.wsk = a;
    koniec.wsk = a;
    size = 1;
}

//Wstawia nowy element do listy dwukierunkowej
//Element ma wartosc v i jest wstawiany za elementem wskazywanym przez iterator it
lista::interator lista::insert_list(interator it, string v){
    ogniwo * a = it.wsk;
    ogniwo * b = new ogniwo;
    ogniwo * c = a->next;
    b->next = c;
    b->prev = a;
    b->value = v;
    c->prev = b;
    a->next = b;
    if(b->next == b)koniec.wsk = b; //popraw koniec listy, jezeli dodajemy za ostatnim elementem
    size++;
    return it;
}

//Usuwa z listy dwukierunkowej element wskazywany przez iteroator it
lista::interator lista::delete_list(interator it){
    ogniwo * b = it.wsk;
    ogniwo * a = b->prev;
    ogniwo * c = b->next;
    a->next = c;
    c->prev = a;
    if(poczatek.wsk == b) poczatek.wsk = c; //popraw poczatek listy, jezeli usuwamy pierwszy element
    if(koniec.wsk == b) koniec.wsk = a;     //popraw koniec listy, jezeli usuwamy ostatni element
    delete b;
    it.wsk =a;
    size--;
    return it;
}

//Zwraca poczatek listy dwukierunkowej
lista::interator lista::begin(){
    return poczatek;
}

//Zwraca koniec listy dwukierunkowej
lista::interator lista::end(){
    return koniec;
}

//Wyswietla zwartosc listy dwukierunkowej
void lista::wyswietl(){
    interator it = poczatek;
    for(int i = 0 ; i < size ; i++){
    cout << it.wsk->value << " ";
    it.wsk = it.wsk->next;
    }
}

//Zwraca wskaznik na kolejny element w liscie dwukierunkowej
lista::interator lista::interator::next(interator it){
    it.wsk = it.wsk->next;
    return it;
}

//Zwraca wskaznik na element o zadanej wartosci v
lista::interator lista::get(string v){
    interator it = poczatek;
    for(int i = 0 ; i < size; i++){
    string x = it.wsk->value;
    if(x ==v) break;
    else it.wsk = it.wsk->next;
    }
    return it;
}
