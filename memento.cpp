#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Memento
{
    string tekst;
    string autor;
    string tytul;
public:
    Memento(string tekst, string autor, string tytul):tekst(tekst),autor(autor),tytul(tytul){}

    string GetTekst()
    {
        return tekst;
    }
    string GetAutor()
    {
        return autor;
    }
    string GetTytul()
    {
        return tytul;
    }

    void SetTekst(string tekst)
    {
        this->tekst=tekst;
    }
    void SetAutor(string autor)
    {
        this->autor=autor;
    }
    void SetTytul(string tytul)
    {
        this->tytul=tytul;
    }
};

class Dokument
{
    string tekst;
    string tytul;
    string autor;
public:
    void SetTekst(string tekst)
    {
        this->tekst=tekst;
    }
    void SetTytul(string tytul)
    {
        this->tytul=tytul;
    }
    void SetAutor(string autor)
    {
        this->autor=autor;
    }

    string GetTekst()
    {
        return tekst;
    }
    string GetAutor()
    {
        return autor;
    }
    string GetTytul()
    {
        return tytul;
    }

    void SetMemento(Memento &m)
    {
        tekst= m.GetTekst();
        autor= m.GetAutor();
        tytul= m.GetTytul();
    }
    Memento *CreateMemento()
    {
        return new Memento(tekst,autor,tytul);
    }
};

int main()
{
    Dokument d;
    d.SetTekst("ggg");
    cout<<d.GetTekst()<<endl;
    auto mem = d.CreateMemento();
    d.SetTekst("aaaa");
    cout<<d.GetTekst()<<endl;
    d.SetMemento(*mem);
    cout<<d.GetTekst()<<endl;

    ofstream zapis("dane.txt");
	zapis<<d.GetTekst()<<endl;
	zapis.close();

    string linia;
    fstream plik;
    cout<<"odczyt z pliku:"<<endl;
    plik.open("dane.txt", ios::in);
    if(plik.good() == true)
    {
        while(!plik.eof())
        {
            getline(plik, linia);
            cout << linia << endl;
        }
        plik.close();
    }

    return 0;
}
