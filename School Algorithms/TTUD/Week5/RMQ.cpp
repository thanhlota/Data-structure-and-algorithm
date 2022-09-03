// common solution using segment tree
// src: https://www.geeksforgeeks.org/range-minimum-query-for-static-array/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
int arr[MAX];
int minVal(int x, int y)
{
    return (x < y) ? x : y;
}
int getMid(int s, int e) { return s + (e - s) / 2; }
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return INT_MAX;
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2 * index + 1),
                  RMQUtil(st, mid + 1, se, qs, qe, 2 * index + 2));
}
int RMQ(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n - 1 || qs > qe)
    {
        cout << "Invalid Input";
        return -1;
    }

    return RMQUtil(st, 0, n - 1, qs, qe, 0);
}

int constructSTUtil(int arr[], int ss, int se,
                    int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] = minVal(constructSTUtil(arr, ss, mid, st, si * 2 + 1),
                    constructSTUtil(arr, mid + 1, se, st, si * 2 + 2));
    return st[si];
}
int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));

    // Maximum size of segment tree
    int max_size = 2 * (int)pow(2, x) - 1;

    int *st = new int[max_size];

    // Fill the allocated memory st
    constructSTUtil(arr, 0, n - 1, st, 0);

    // Return the constructed segment tree
    return st;
}

// Driver program to test above functions
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    vector<pair<int, int>> v(k);
    for (int i = 0; i < k; i++)
        cin >> v[i].first >> v[i].second;
    long long sum = 0;
    // Build segment tree from given array
    int *st = constructST(arr, n);
    for (int i = 0; i < k; i++)
    {
        sum += RMQ(st, n, v[i].first, v[i].second);
    }
    cout << sum;
    // system("pause");
    return 0;
}
