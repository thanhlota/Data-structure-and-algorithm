#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[100];
    int n;
    vector<int> pos, ne, zero;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < 0)
        {
            ne.push_back(arr[i]);
        }
        else if (arr[i] > 0)
        {
            pos.push_back(arr[i]);
        }
        else
        {
            zero.push_back(arr[i]);
        }
    }
    int tmp;
    if (ne.size() % 2 == 0)
    {
        tmp = ne.back();
        ne.pop_back();
        zero.push_back(tmp);
    }
    if (pos.size() == 0)
    {
        tmp = ne.back();
        ne.pop_back();
        pos.push_back(tmp);
        tmp = ne.back();
        ne.pop_back();
        pos.push_back(tmp);
    }
    cout << ne.size() << " ";
    for (int i = 0; i < ne.size(); i++)
        cout << ne[i] << " ";
    cout << endl;
    cout << pos.size() << " ";
    for (int i = 0; i < pos.size(); i++)
        cout << pos[i] << " ";
    cout << endl;
    cout << zero.size() << " ";
    for (int i = 0; i < zero.size(); i++)
        cout << zero[i] << " ";
    cout << endl;
}