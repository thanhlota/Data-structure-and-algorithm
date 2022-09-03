#include <iostream>
int arr[100];
int check[100]{0};
using namespace std;
void printSolution(int k)
{
    for (int i = 1; i <= k; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void Try(int k, int v, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            check[i] = 1;
            arr[k] = i;
            if (k == v)
                printSolution(v);
            else

                Try(k + 1, v, n);
            check[i] = 0;
        }
    }
}
int main()
{

    Try(1, 3, 5);
    system("pause");
}
