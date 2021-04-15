#include <iostream>

using namespace std;

class CzlowiekZnanyZWidzenia
{
public:
    CzlowiekZnanyZWidzenia(const string &cecha=""):cecha(cecha)
    {}
    void setcecha(const string &Cecha)
    {
        cecha=Cecha;
    }
    string getcecha() const
    {
        return cecha;
    }
private:
    string cecha;
};

class CzlowiekZnanyZImienia:public CzlowiekZnanyZWidzenia
{
public:
    CzlowiekZnanyZImienia(const string &imie="",const string &cecha=""):imie(imie), CzlowiekZnanyZWidzenia(cecha)
    {}

    void setimie(const string &Imie)
    {
        imie=Imie;
    }
    string getimie() const
    {
        return imie;
    }
private:
    string imie;
};

class Zwierze
{

};

class DobrzeZnanyKolega:public CzlowiekZnanyZImienia
{
public:
    DobrzeZnanyKolega(const string &cecha, const string &imie, const string & skadgoznam, const Zwierze &zwierze):CzlowiekZnanyZImienia(imie,cecha), skadgoznam(skadgoznam), zwierze(zwierze){}

    void setskadgoznam(string Skadgoznam)
    {
        skadgoznam=Skadgoznam;
    }

    string getskadgoznam() const
    {
        return skadgoznam;
    }
private:
    string skadgoznam;
    Zwierze zwierze;
};



int main()
{
    DobrzeZnanyKolega kolega("gruby","Pawel","pilka",Zwierze());
    cout<<kolega.getcecha()<<" "<<kolega.getimie()<<" "<<kolega.getskadgoznam()<<endl;

    return 0;
}
