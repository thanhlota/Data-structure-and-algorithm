#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int *arr = new int[n];
    int i;
    for (i = 0; i < n; i++)
        cin >> arr[i];
    int maximus = arr[0];
    int nmax = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (nmax > 0)
        {
            nmax = nmax + arr[i];
        }
        else
            nmax = arr[i];
        maximus = (nmax < maximus) ? maximus : nmax;
    }
    cout << maximus;
    system("pause");
}