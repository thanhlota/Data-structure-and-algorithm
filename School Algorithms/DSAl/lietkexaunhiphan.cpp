#include <iostream>
#define Max 5
using namespace std;
int arr[Max];
int k = 0;
void output()
{
    for (int i = 0; i < 5; i++)
        cout << arr[i];
    cout << endl;
}
void Try(int n)
{

    for (int i = 0; i <= 1; i++)
    {
        if (arr[n - 1] + i < 2)
        {
            arr[n] = i;
            if (n == 4)
                output();
            else
                Try(n + 1);
        }
    }
}
int main()
{
    arr[0] = 0;
    Try(1);
    system("pause");
}