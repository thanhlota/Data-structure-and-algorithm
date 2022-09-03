#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    cin >> n;
    // vector<string> vec;
    vector<string> res;
    // int j = 0;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        if (tmp.length() <= 10)
            res.push_back(tmp);
        else
        {
            int l = tmp.length() - 1;
            tmp = tmp[0] + to_string(l - 1) + tmp[l];
            res.push_back(tmp);
        }
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << "\n";
    // system("pause");
}