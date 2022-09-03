#include <bits/stdc++.h>
using namespace std;
// 11 000 11 000 11 000
//  2 3 3 3 2
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> dp;
        vector<pair<int, char>> vp;
        for (int i = 0; i < n;)
        {
            int tmp = 1;
            while (i + 1 < n && s[i] == s[i + 1])
            {
                tmp += 1;
                i++;
            }
            dp.push_back(tmp);
            vp.push_back({tmp, s[i]});
            i++;
        }

        int res = 0, cnt = 0;
        for (int i = 0; i < dp.size();)
        {
            if (dp[i] % 2 == 1)
            {
                if (dp[i + 1] % 2 == 1)
                {
                    res += 1;
                    i += 2;
                }
                else
                {
                    res += 1;
                    dp[i + 1]++;
                    i += 1;
                }
            }
            else
                i++;
        }
        char rem = s[0];
        for (int i = 0; i < vp.size(); i++)
        {
            if (vp[i].first == 0)
                continue;
            if (vp[i].first % 2 == 1)
            {
                if (vp[i + 1].first % 2 == 1)
                {
                    if (vp[i].first == 1)
                    {
                        vp[i].first = 0;
                        vp[i + 1].first++;
                    }
                    else if (vp[i + 1].first == 1)
                    {
                        vp[i].first++;
                        vp[i + 1].first = 0;
                        cnt += 1;
                        if (i >= 1 && vp[i - 1].first == 0)
                        {
                            if (vp[i].second == rem)
                            {
                                cnt -= 1;
                            }
                            else
                                rem = vp[i].second;
                        }
                    }
                    else
                    {
                        vp[i].first++;
                        vp[i + 1].first--;
                        cnt += 1;
                        if (i >= 1 && vp[i - 1].first == 0)
                        {
                            if (vp[i].second == rem)
                            {
                                cnt -= 1;
                            }
                            else
                                rem = vp[i].second;
                        }
                    }
                }
                else
                {
                }
            }
            else
            {
                cnt += 1;
                if (i >= 1 && vp[i - 1].first == 0)
                {
                    if (vp[i].second == rem)
                    {
                        cnt -= 1;
                    }
                    else
                        rem = vp[i].second;
                }
            }
        }
        cout << res << " " << cnt << "\n";
    }
}