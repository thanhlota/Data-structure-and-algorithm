#include <iostream>
#define Max 100
using namespace std;
int arr[Max];
void printSolution(int n)
{
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void Try(int k, int n, int v)
{
    for (int i = arr[v - 1] + 1; i <= n - k + v; i++)
    {
        arr[v] = i;
        if (v == k)
            printSolution(k);
        else
            Try(k, n, v + 1);
    }
}
int main()
{
    arr[0] = 0;
    cout << 2 / 3;
    Try(3, 5, 1);
    system("pause");
}