#include <bits/stdc++.h>
using namespace std;
bool match(char a, char b)
{
    if (a == '(' && b == ')')
        return true;
    if (a == '[' && b == ']')
        return true;
    return false;
}
int countBracket(string s, int l, int r)
{
    int cnt = 0;
    for (int i = l + 1; i < r; i++)
    {
        if (s[i] == '[')
            cnt++;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 0;
    string s;
    cin >> s;
    // cout << s.length();
    stack<char> bracket;
    deque<int> index;
    int l, r, tmp, start = 0, end = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || bracket.empty())
        {
            bracket.push(s[i]);
            index.push_front(i);
        }
        else if (match(bracket.top(), s[i]))
        {
            bracket.pop();
            index.pop_front();
        }
        else
        {
            bracket.push(s[i]);
            index.push_front(i);
        }
    }
    if (bracket.empty())
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '[')
                cnt += 1;
        }
        if (cnt == 0)
            cout << 0;
        else
        {
            cout << cnt << endl;
            cout << s;
            return 0;
        }
    }
    l = -1;
    while (!index.empty())
    {
        r = index.back();
        index.pop_back();
        if (r - l == 1)
        {
            l = r;
            continue;
        }
        else
        {
            tmp = countBracket(s, l, r);
            if (tmp > cnt)
            {
                cnt = tmp;
                start = l + 1;
                end = r - 1;
            }
            l = r;
        }
    }
    if (l != (s.size() - 1))
    {
        tmp = countBracket(s, l, s.size());
        if (tmp > cnt)
        {
            cnt = tmp;
            start = l + 1;
            end = s.size() - 1;
        }
    }
    if (cnt == 0)
        cout << 0;
    else
    {
        cout << cnt << endl;
        for (int i = start; i <= end; i++)
            cout << s[i];
    }
    // cout.flush();
    // system("pause");
}