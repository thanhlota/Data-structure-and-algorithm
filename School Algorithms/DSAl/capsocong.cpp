#include <iostream>
using namespace std;
int arr[]{1, 4, 5, 2, 6, 9, 7, 8, 5, 3, 1};
int s[100]{1};
int maximus = 1;
int main()
{
    for (int i = 1; i < 11; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == (arr[j] + 1))
            {
                s[i] = max(s[j] + 1, s[i]);
            }
        }
        maximus = max(maximus, s[i]);
    }
    cout << maximus << endl;
    system("pause");
}