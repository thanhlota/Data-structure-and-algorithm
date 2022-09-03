#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<long long> st1; // start with positive integer
        long long sum1 = 0;
        vector<long long> st2; // start with negative integer
        long long sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            int sz1 = st1.size();
            int sz2 = st2.size();
            if (sz1 == sz2)
            {
                if (sz1 & 1)
                {
                    if (a[i] < 0)
                    {
                        sum1 += a[i];
                        st1.push_back(a[i]);
                    }
                    else
                    {
                        sum2 += a[i];
                        st2.push_back(a[i]);
                    }
                }
                else
                {
                    if (a[i] > 0)
                    {
                        st1.push_back(a[i]);
                        sum1 += a[i];
                    }
                    else
                    {
                        sum2 += a[i];
                        st2.push_back(a[i]);
                    }
                }
            }
            else if (sz1 > sz2)
            {
                if (sz1 & 1)
                {
                    int tmp = st1[sz1 - 1];
                    if (a[i] < 0)
                    {
                        sum1 += a[i];
                        st1.push_back(a[i]);
                    }
                    else
                    {
                        if (a[i] > tmp)
                        {
                            st1[sz1 - 1] = a[i];
                            sum1 += a[i] - tmp;
                        }
                        else
                        {
                            if (sz2 & 1)
                            {
                                st2.push_back(a[i]);
                            }
                        }
                    }
                }
                else
                {
                    if (a[i] > 0)
                    {
                        sum1 += a[i];
                        st1.push_back(a[i]);
                    }
                    else
                    {

                        int tmp = st1[sz1 - 1];
                        if (!(sz2 & 1))
                        {
                            if (a[i] > tmp)
                            {
                                st1[sz1 - 1] = a[i];
                                sum1 += a[i] - tmp;
                            }
                            else
                                st2.push_back(a[i]);
                        }
                        else
                        {
                            if (a[i] > tmp)
                            {
                                st1[sz1 - 1] = a[i];
                                sum1 += a[i] - tmp;
                            }
                        }
                    }
                }
            }
            else
            {
                if (sz2 & 1)
                {
                    int tmp = st2[sz2 - 1];
                    if (a[i] > 0)
                    {
                        sum2 += a[i];
                        st2.push_back(a[i]);
                    }
                    else
                    {
                        if (sz1 & 1)
                        {
                            if (a[i] > tmp)
                            {
                                st2[sz2 - 1] = a[i];
                                sum2 += a[i] - tmp;
                            }
                            else
                                st1.push_back(a[i]);
                        }
                        else
                        {
                            if (a[i] > tmp)
                            {
                                st2[sz2 - 1] = a[i];
                                sum2 += a[i] - tmp;
                            }
                        }
                    }
                }
                else
                {
                    if (a[i] < 0)
                    {
                        sum2 += a[i];
                        st2.push_back(a[i]);
                    }
                    else
                    {

                        int tmp = st2[sz2 - 1];
                        if (!(sz1 & 1))
                        {
                            if (a[i] > tmp)
                            {
                                st2[sz2 - 1] = a[i];
                                sum2 += a[i] - tmp;
                            }
                            else
                                st1.push_back(a[i]);
                        }
                        else
                        {
                            if (a[i] > tmp)
                            {
                                st2[sz2 - 1] = a[i];
                                sum2 += a[i] - tmp;
                            }
                        }
                    }
                }
            }
        }
        if (st1.size() == st2.size())
        {
            if (sum1 > sum2)
                cout << sum1;
            else
                cout << sum2;
        }
        else
        {
            if (st1.size() < st2.size())
                cout << sum2;
            else
                cout << sum1;
        }
        cout << "\n";
    }
}