#include <iostream>
using namespace std;
int main()
{
    int n, b;
    cin >> n;
    cin >> b;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int *left = new int[n];
    int maxLeft = left[0] = arr[0];
    int *right = new int[n];
    int maxRight = right[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        maxLeft = left[i] = max(maxLeft, arr[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        maxRight = right[i] = max(maxRight, arr[i]);
    }
    int maximus = -1;
    for (int i = 1; i < n - 1; i++)
    {
        int tmp1 = left[i - 1] - arr[i];
        int tmp2 = right[i + 1] - arr[i];
        if (tmp1 >= b && tmp2 >= b)
            maximus = max(maximus, tmp1 + tmp2);
    }
    cout << maximus;
    // system("pause");
}