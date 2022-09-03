#include <iostream>
using namespace std;
// Ban co size 5x5
int arr[6][6]{0};
bool check(int k, int v)
{
    for (int i = 1; i <= 5; i++)
        if (arr[k][i])
            return false;
    for (int i = 1; i <= 5; i++)
        if (arr[i][v])
            return false;
    int a = min(k, v);
    int b = min(5 - k, 5 - v);
    for (int i = 1; i <= a; i++)
        if (arr[k - i][v - i] | arr[k - i][v + i] | arr[k + i][v - i])
            return false;
    for (int i = 1; i <= b; i++)
        if (arr[k + i][v + i])
            return false;
    return true;
}
void printSolution()
{
    for (int k = 1; k <= 5; k++)
        for (int i = 1; i <= 5; i++)
            if (arr[k][i])
                cout << i << " ";
    cout << endl;
}
void Try(int k)
{
    for (int i = 1; i <= 5; i++)
    {
        if (check(k,i))
        {
            arr[k][i] = 1;
            if (k == 5)
                printSolution();
            else
            Try(k + 1);
            arr[k][i] = 0;
        }
    }
}
int main()
{
    Try(1);
    system("pause");
}