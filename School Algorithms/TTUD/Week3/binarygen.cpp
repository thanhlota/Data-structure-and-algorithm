#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string S;
    cin >> n;
    cin >> S;
    int j = n - 1;
    while (S[j] != '0' && j >= 0)
    {
        S[j] = '0';
        j--;
    }
    if (j < 0)
    {
        cout << "-1";
        return 0;
    }
    S[j] = '1';
    cout << S;
    // system("pause");
}