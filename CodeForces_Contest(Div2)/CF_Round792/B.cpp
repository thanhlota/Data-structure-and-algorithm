#include <bits/stdc++.h>
using namespace std;
// x mod y = a y mod z= b z mod x =c
// x = k1y+a y= k2z+b z= k3x+c  (a<y, b<z, c<x)
// x= y+a y=z+b z=x+c a<z+b, b<x+c c<y+a // z>a-b x>b-c y>c-a  // x=k1(k2z+b)+a= k1(k2(k3x+c)+b)+a =>
// x= k1k2k3x+k1k2c+k1b+a
// x=(k1k2c+k1b+a)/(1-k1k2k3);x=k1k2c+k1b; y= k2c+b;
// y=(k2(k3(k1y+a)+c)+b) => y= (k2k3a+k2c+b)/..
// z=(k1k3b+k3a+c)/.....
//

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int x, y, z;
        z = c;
        x = a + b + c;
        y = b + c;
        if (x % y == a && y % z == b && z % x == c)
        {
            continue;
            cout << x << " " << y << " " << z;
        }

        cout << "\n";
    }
}