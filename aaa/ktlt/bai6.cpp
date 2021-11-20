#include <iostream>
using namespace std;
typedef struct Phanso
{
    int tuso;
    int mauso;
} PS;
int UCLN(int a, int b)
{
    while ( a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    return a; // or return b; a = b
}

void rutgon(PS &a)
{
    if(a.tuso==0) return;
    int temp=a.tuso;
    a.tuso = a.tuso / UCLN(a.tuso, a.mauso);
    a.mauso = a.mauso / UCLN(temp, a.mauso);
    if (a.tuso < 0 && a.mauso < 0)
    {
        a.tuso = abs(a.tuso);
        a.mauso = abs(a.mauso);
    }
    else if (a.mauso < 0)
    {
        a.tuso = -a.tuso;
        a.mauso = abs(a.mauso);
    }
}
istream &operator>>(istream &is, PS &obj)
    {
        cout << "Nhap tu so: ";
        is >> obj.tuso;
        cout << "Nhap mau so: ";
        is >> obj.mauso;
        return is;
    }
ostream &operator<<(ostream &os, PS obj)
    {
        os << obj.tuso << "/" << obj.mauso << endl;
        return os;
    }
PS operator+(PS a, PS b)
{
    rutgon(a);
    rutgon(b);
    PS res;
    res.tuso = a.tuso * b.mauso + a.mauso * b.tuso;
    res.mauso = a.mauso * b.mauso;
    rutgon(res);
    return res;
}

PS operator-(PS a, PS b)
{
    rutgon(a);
    rutgon(b);
    PS res;
    res.tuso = a.tuso * b.mauso - a.mauso * b.tuso;
    res.mauso = a.mauso * b.mauso;
    rutgon(res);
    return res;
}

PS operator*(PS a, PS b)
{
    rutgon(a);
    rutgon(b);
    PS res;
    res.tuso = a.tuso * b.tuso;
    res.mauso = a.tuso * b.mauso;
    rutgon(res);
    return res;
}

PS operator/(PS a, PS b)
{
    rutgon(a);
    rutgon(b);
    PS res;
    res.tuso = a.tuso * b.mauso;
    res.mauso = a.mauso * b.tuso;
    rutgon(res);
    return res;
}
PS& operator ++(PS &a){
       a.tuso=a.tuso+a.mauso;
       return a;
}
PS operator ++(PS &a,int){
    PS c=a;
    a.tuso= a.tuso+ a.mauso;
    return c;
}
int main()
{
    PS ps1, ps2,ps3;
    cin>>ps1>>ps2>>ps3;
    PS ps4= ps1+ps2+ps3;
    ps4++;
    cout<<ps4;
    system("pause");
}