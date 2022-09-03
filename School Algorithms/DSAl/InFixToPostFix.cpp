// #include <iostream>
// using namespace std;
// void selectionSort(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[i] > arr[j])
//             {
//                 int tmp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = tmp;
//             }
//         }
//     }
// }
// void bubbleSort(int arr[], int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j < n - i; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 int tmp = arr[j];
//                 arr[i] = arr[j];
//                 arr[j] = tmp;
//             }
//         }
//     }
// }
// void insertionSort(int arr[], int n)
// {
// }
// int main()
// {
//     int arr[1000];
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     bubbleSort(arr, n);
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";
// }
// #include <iostream>
// using namespace std;
// void insertionSort(int arr[], int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = i - 1; j >= 1; j--)
//         {
//             if (arr[i] < arr[j] && arr[i] > arr[j - 1])
//             {
//                 int tmp = arr[j];
//                 arr[j] = arr[i];
//             }
//         }
//     }
// }
// int main()
// {
//     int n;
//     int arr[10000];
//     cin >> n;
//     arr[0] = INT_MIN;
//     for (int i = 1; i <= n; i++)
//         cin >> arr[i];
//     insertionSort(arr, n);
//     for (int i = 1; i <= n; i++)
//         cout << arr[i] << " ";
//     return 0;
// }
//  void selectionSort(int arr[], int start,int interval, int n)
// {
//     for (int i = start; i < n - 1; i+=interval)
//     {
//         for (int j = i + interval; j < n; j+=interval)
//         {
//             if (arr[i] > arr[j])
//             {
//                 int tmp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = tmp;
//             }
//         }
//     }
// }
// void shellSort(int a[],int n){
//     int interval =n/2;
//     while(interval>=1){
//        for(int i=0;i<interval;i++){
//           selectionSort(a,i,interval,n);
//        }
//      interval=interval/2;
//     }
// }
#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int tmp[10000];
    int pos1 = m + 1;
    int pos2 = 0;
    while (l <= m && pos1 <= r)
    {
        if (arr[l] >= arr[pos1])
        {
            tmp[pos2] = arr[pos1];
            pos1++;
        }
        else
        {
            tmp[pos2] = arr[l];
            l++;
        }
        pos2++;
    }
    if (pos1 > r)
    {
        for (int i = l; i <= m; i++)
        {
            tmp[pos2++] = arr[i];
        }
    }
    else
    {
        for (int i = pos1; i <= r; i++)
        {
            tmp[pos2++] = arr[i];
        }
    }
    for (int i = l; i <= r; i++)
        arr[i] = tmp[i];
}
void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int a[100001];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, n - 1);
    printArray(a, n);

    return 0;
}