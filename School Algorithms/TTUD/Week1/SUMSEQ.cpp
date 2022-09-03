#include <iostream>
using namespace std;
const unsigned long long P = 1000000000 + 7;
int main()
{
    unsigned long long n,res=0;
    cin >> n;
    unsigned long long *arr = new unsigned long long[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        res += arr[i] - P * (arr[i] / P);
        res = res - P * (res / P);
    }
    cout << res;
}