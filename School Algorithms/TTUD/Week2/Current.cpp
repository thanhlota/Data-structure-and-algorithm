#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    stack<char> St;
    St.push(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        if (!St.empty())
        {
            char tmp = St.top();
            if (s[i] == tmp)
            {
                St.pop();
                continue;
            }
        }
        St.push(s[i]);
    }
    if (St.empty())
        cout << "Yes";
    else
        cout << "No";
    // system("pause");
}