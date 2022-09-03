//another foolish solution (make thing simpler !)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v(6);
    vector<int> res(4);
    int sum = 4 + 8 + 15 + 16 + 23 + 42;
    for (int i = 0; i < 4; i++)
    {
        cout << "? " << i + 1 << " " << i + 2 << endl;
        cin >> res[i];
    }
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            int gcd = __gcd(res[i], res[i + 1]);
            if (gcd % 7 == 0)
            {
                v[i + 1] = 42;
            }
            else if (gcd % 5 == 0)
            {
                v[i + 1] = 15;
            }
            else if (gcd % 23 == 0)
            {
                v[i + 1] = 23;
            }
            else
            {
                if (res[i] % 5 == 0 || res[i] % 7 == 0 || res[i] % 23 == 0 || res[i + 1] % 5 == 0 || res[i + 1] % 7 == 0 || res[i + 1] % 23 == 0)
                {
                    if (res[i] % 7 == 0)
                    {
                        v[i + 1] = res[i] / 42;
                    }
                    else if (res[i + 1] % 7 == 0)
                        v[i + 1] = res[i + 1] / 42;
                    else
                        v[i + 1] = gcd;
                }
                else
                {
                    int tmp = abs(res[i] - res[i + 1]);
                    if (tmp == 32)
                        v[i + 1] = 4;
                    else if (tmp == 96)
                        v[i + 1] = 8;
                    else if (tmp == 64)
                        v[i + 1] = 16;
                }
            }
            v[i] = res[i] / v[i + 1];
            v[i + 2] = res[i + 1] / v[i + 1];
        }
        else
            v[i + 1] = res[i] / v[i];
    }
    v[5] = sum - v[0] - v[1] - v[2] - v[3] - v[4];
    cout << "! ";
    for (int i = 0; i < 6; i++)
        cout << v[i] << " ";
    // system("pause");
}