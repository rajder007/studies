#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

class String
{
public:
    String()
    {
        rozmiar=0;
        tekst=new char[rozmiar];
    }
    String(const String &tekst)
    {
        rozmiar=tekst.rozmiar;
        this -> tekst=new char[rozmiar];
        strcpy(this -> tekst,tekst.tekst);
    }

    ~String()
    {
        delete[] tekst;
    }

    String(const char* tekst)
    {
        rozmiar=strlen(tekst);
        char* tekst1= new char[rozmiar+1];
        strcpy(tekst1,tekst);
    }
    void setNewText(const char* NewText)
    {
        int nowyrozmiar=strlen(NewText);
        char* newtext=new char[nowyrozmiar+1];
        delete[] tekst;
        tekst=newtext;
        rozmiar=nowyrozmiar;
        tekst= new char[rozmiar+1];
        strcpy(tekst,NewText);
    }
    String &operator=(const char* NewText)
    {
        setNewText(NewText);
        return *this;
    }
    String &operator=(String NewText)
    {
        swap(tekst,NewText.tekst);
        return *this;
    }
    int size1() const
    {
        return rozmiar;
    }
    const char* text() const
    {
        return tekst;
    }
    String &operator+=(const char* text2Append)
    {
        int nowy_rozmiar=rozmiar+strlen(text2Append)+1;
        char *nowy_tekst= new char[nowy_rozmiar];
        strcpy(nowy_tekst,tekst);
        strcpy(nowy_tekst+rozmiar,text2Append);
        delete[] tekst;
        tekst=nowy_tekst;
        rozmiar=nowy_rozmiar;
        return *this;
    }
    String operator+(const char* text2Append) const
    {
        String text_sum(*this);
        text_sum+=text2Append;
        return text_sum;
    }

    friend ostream&operator<<(ostream &wyjscie,const String &tekst)
    {
        return wyjscie<<tekst.tekst;
    }

    friend istream&operator>>(istream &wyjscie, String &tekst)
    {
        while (true)
        {
         char newChar = wyjscie.get();
         if (newChar != '\n')
         {
             char buffer[2] = {newChar, '\0'};
             tekst += buffer;
         }
         else
            break;
        }
        return wyjscie;
    }

private:
    char* tekst;
    int rozmiar;
};

int main()
{
    String p1("lala");
    p1.setNewText("aaa");
    cout<<p1.size1()<<endl;
    cout<<p1.text()<<endl;
    cout<<p1<<endl;
    cin >> p1;
    cout<<p1<<endl;

    return 0;
}
