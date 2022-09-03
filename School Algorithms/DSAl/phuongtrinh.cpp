#include <iostream>
using namespace std;
#define Max 100
// Phuong trinh co dang: a1y1+a2y2+a3y3+....+anyn=sum
// So luong he so
int n;
// Tong
int sum;
int he_so[Max]{1, 3,1,2};
int arr[Max]{0};
void printSol()
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void Try(int k, int left)
{
    for (int i = 1; i <= left / he_so[k]; i++)
    {
        arr[k] = i;
        left -= i * he_so[k];
        if (k == n - 1)
        {
            if (left == 0)
                printSol();
            else
            {
                left += i * he_so[k];
            }
        }
        else
            Try(k + 1, left);
        left += i * he_so[k];
    }
}
int main()
{
    n = 4;
    sum = 15;
    Try(0, sum);
    system("pause");
}