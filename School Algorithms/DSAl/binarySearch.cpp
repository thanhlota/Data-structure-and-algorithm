#include <iostream>
using namespace std;
int binarySearch(int a[], int l, int r, int x)
{
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (a[mid] >= x)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (a[l] == x)
        return l;
    else
        return -1;
}
// void quicksort(int a[],int l,int r){
//     int pivot=(l+r)/2;
//     int i=l;
//     int j=r;
//     while(i<j){
//     while(a[i]<a[pivot]){
//       i++;
//     }
//     while(a[j]>a[pivot]){
//       j--;
//     }
//     if(i<=j){
//         int tmp=a[i];
//         a[i]=a[j];
//         a[j]=tmp;
//         i++;
//         j--;
//     }
//     if(i<r) quicksort(a,i,r);
//     if(j>l) quicksort(a,j,r);
//     }
// }
int main()
{
    int n, a[100001], s, start = 0, end = -1;
    int b[100001];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> s;
    b[0] = a[0];
    for (int i = 1; i < n; i++)
        b[i] = b[i - 1] + a[i];
    for (int i = 0; i < n - 1; i++)
    {
        if (b[i] == s)
        {
            end = i;
            break;
        }
        end = binarySearch(b, i + 1, n - 1, s + b[i]);
        if (end != -1)
        {
            start = i + 1;
            break;
        }
    }
    if (end == -1)
        cout << "-1";
    else
    {
        for (int i = start; i <= end; i++)
            cout << a[i] << " ";
    }
    system("pause");
}
