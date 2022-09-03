#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[100000];
    int res[100000];
    int tmp;
    int n;
    cin >> n;
    // hang doi gom cac gia tri lon hon chi so cua vi tri xa nhat nho hon cua phan tu truoc no
    deque<int> right;
    // hang doi gom cac gia tri nho hon chi so cua vi tri xa nhat
    deque<int> left;
    left.push_back(n - 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        res[i] = -1;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
        {
            while (!right.empty())
            {
                tmp = right.back();
                if (arr[tmp] < arr[i])
                {
                    right.pop_back();
                    left.push_front(tmp);
                }
                else
                    break;
            }
        }
        while (!left.empty())
        {
            tmp = left.front();
            // if (tmp <= i)
            //     break;
            if (arr[tmp] < arr[i])
            {
                res[i] = tmp - i - 1;
                break;
            }
            left.pop_front();
            right.push_back(tmp);
        }
        tmp = left.back();
        if (arr[i] < arr[tmp])
            left.push_back(i);
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    // system("pause");
}
