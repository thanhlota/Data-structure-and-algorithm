#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;
long long area(vector<long long> vec)
{
    long long tmp;
    long long maximus = -1;
    deque<long long> s;
    long long pos = 0;
    long long hist[vec.size()];
    // long long pre[vec.size()];
    // pre[0]=0;
    s.push_front(0);
    for (long long i = 1; i < vec.size(); i++)
    {
        tmp = s.front();
        while (vec[tmp] > vec[i])
        {
            s.pop_front();
            if (!s.empty())
            {
                long long k = s.front();
                hist[tmp] = i - k - 1;
                tmp = s.front();
            }
            else
            {
                hist[tmp] = i;
                break;
            }
        }
        s.push_front(i);
    }
    long long index = tmp = s.front();
    // long long l = tmp - prep + 1;
    while (!s.empty())
    {
        s.pop_front();
        if (!s.empty())
        {
            long long k = s.front();
            hist[index] = tmp - k;
            index = s.front();
        }
        else
        {
            hist[index] = tmp + 1;
        }
    }
    for (long long i = 0; i < vec.size(); i++)
        maximus = max(maximus, hist[i] * vec[i]);
    return maximus;
}
int main()
{
    cout << sizeof(int);
    vector<vector<long long>> h;
    long long cnt = 0;
    long long tmp;
    cin >> tmp;
    long long a;
    while (tmp != 0)
    {
        vector<long long> v;
        for (long long i = 0; i < tmp; i++)
        {
            cin >> a;
            v.push_back(a);
        }
        h.push_back(v);
        cnt++;
        cin >> tmp;
    }
    for (long long i = 0; i < cnt; i++)
    {
        cout << area(h[i]) << endl;
    }
    // system("pause");
    return 0;
}
