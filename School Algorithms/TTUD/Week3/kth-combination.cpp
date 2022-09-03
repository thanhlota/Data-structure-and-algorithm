#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int n, m, k;
int arr[MAX];
void printSol()
{
    for (int i = 0; i < m; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    cin >> n >> m >> k;
    // lỗi xàm vl :))
    if (m > n)
    {
        cout << "-1";
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        arr[i] = i + 1;
    }
    k--;
    while (k > 0)
    {
        int foo = m - 1;
        if (arr[foo] != n)
        {
            arr[foo]++;
        }
        else
        {
            while (arr[foo] - arr[foo - 1] == 1)
                foo--;
            foo--;
            if (foo < 0)
            {
                cout << "-1";
                // system("pause");
                return 0;
            }
            else
            {
                arr[foo]++;
                for (int i = foo + 1; i < m; i++)
                    arr[i] = arr[foo] + i - foo;
            }
        }
        k--;
    }
    printSol();
    // system("pause");
    return 0;
}