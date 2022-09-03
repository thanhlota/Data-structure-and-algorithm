#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int arr[]{0,2, 1, 3, 2, 8, 5, 7};
int maximus = 1;
int main()
{
    s.push(maximus);
    for (int i = 1; i < 8; i++)
    {
        if (arr[i] < arr[maximus])
        {
            while (1)
            {
                int tmp = s.top();
                if (arr[tmp] > arr[i])
                {
                    cout << tmp << " ";
                    break;
                }
                s.pop();
            }
            s.push(i);
        }
        else
        {
            maximus = i;
            while (s.empty())
                s.pop();
            s.push(maximus);
            cout << -1 << " ";
        }
    }
    system("pause");
}