#include <iostream>
using namespace std;
const int MAX = 100;
int n1 = 7;
int a[]{3, 7, 2, 5, 1, 4, 9};
int n2 = 10;
int b[]{4, 3, 2, 3, 6, 1, 5, 4, 9, 7};
int trace1{MAX}, trace2{MAX};
// int trace1[MAX]{};
// int trace2[MAX]{-1};
int c[MAX][MAX]{0};
int main()
{
    for (int i = 0; i < n2; i++)
    {
        if (b[i] == a[0])
        {
            trace1 = i;
            break;
        }
    }
    for (int i = 0; i < n1; i++)
    {
        if (a[i] == b[0])
        {
            trace2 = i;
            break;
        }
    }
    for (int i = trace1; i < n2; i++)
        c[0][i] = 1;
    for (int i = trace2; i < n1; i++)
        c[i][0] = 1;
    for (int i = 1; i < n1; i++)
    {
        for (int j = 1; j < n2; j++)
        {
            if (a[i] == b[j])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i][j - 1], c[i - 1][j]);
        }
    }
    cout << c[n1 - 1][n2 - 1] << endl;
    system("pause");
}