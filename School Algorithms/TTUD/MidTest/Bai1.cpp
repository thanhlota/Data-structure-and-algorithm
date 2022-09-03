#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ifstream ifs("D:\\new project\\School Algorithms\\TTUD\\MidTest-testcase\\test4.txt");
    // ofstream ofs("D:\\new project\\School Algorithms\\TTUD\\MidTest-testcase\\res4.txt");
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        // cout.flush();
    }
    vector<int> dp(n, 1);
    stack<int> st;
    int res = 1;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty())
        {
            int t = st.top();
            if (v[i] > v[t])
            {
                dp[i] = dp[t] + 1;
                break;
            }
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++)
        res = max(res, dp[i]);
    cout << res;
    // system("pause");
}