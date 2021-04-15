#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
public:
    Matrix():tab1(2, vector<double>(2, 0.))
    {
    counter ++;
    }
    Matrix(int a, int b, int c, int d):Matrix()
    {
        tab1[0][0]=a;
        tab1[0][1]=b;
        tab1[1][0]=c;
        tab1[1][1]=d;
    }
    Matrix(const Matrix &m): tab1(m.tab1)
    {
       counter++;
    }
    static int instances()
    {
        return counter;
    }
    ~Matrix()
    {
        counter--;
    }
    Matrix operator +(const Matrix &m) const
    {
        Matrix sum;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                sum.tab1[i][j]=this->tab1[i][j]+m.tab1[i][j];
            }
        }
        return sum;
    }
    Matrix operator*(const Matrix &m)const
    {
        return Matrix(tab1[0][0] * m.tab1[0][0] + tab1[0][1]*m.tab1[1][0],
               tab1[0][0] * m.tab1[0][1] + tab1[0][1]*m.tab1[1][1],
               tab1[1][0] * m.tab1[0][0] + tab1[1][1]*m.tab1[1][0],
               tab1[1][0] * m.tab1[0][1] + tab1[1][1]*m.tab1[1][1]);
    }
    double *operator[](int index)
    {
        return &tab1[index][0];
    }
    int operator()() const
    {
        return tab1[0][0]*tab1[1][1] - tab1[0][1]*tab1[1][0];
    }
    friend ostream & operator<<(ostream &wyj, const Matrix &m)
    {
        return wyj<<m.tab1[0][0]<<" "<<m.tab1[0][1]<<"\n"<<m.tab1[1][0]<<" "<<m.tab1[1][1]<<endl;
    }
    friend istream & operator>>(istream &wyj,Matrix &m)
    {
        return wyj>>m.tab1[0][0]>>m.tab1[0][1]>>m.tab1[1][0]>>m.tab1[1][1];
    }
private:
    vector<vector<double>> tab1;
    static int counter;
};
int Matrix::counter=0;

int main()
{
    cout<<Matrix::instances()<<endl;
    Matrix m;
    cin >>m;
    cout<<m<<endl;

    return 0;
}
