#include <iostream>
using namespace std;
int arr[1000000];
void quickSort(int arr[], int l, int r)
{
    int pivot = (r + l) / 2;
    int i = l;
    int j = r;
    int value = arr[pivot];
    while (i < j)
    {
        while (arr[i] < value)
        {
            i++;
        }
        while (arr[j] > value)
        {
            j--;
        }
        if (i <= j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (i < r)
    {
        quickSort(arr, i, r);
    }
    if (l < j)
    {
        quickSort(arr, l, j);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    // system("pause");
}