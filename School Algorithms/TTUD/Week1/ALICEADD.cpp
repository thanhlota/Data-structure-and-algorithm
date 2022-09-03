#include <iostream>
#define MAX 100
using namespace std;
int c[MAX]{0};
int pos1 = MAX - 1, pos2 = MAX - 1, pos3 = MAX - 1;
void add(string num1, string num2)
{
    int a[MAX]{0};
    int b[MAX]{0};
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    while (i >= 0)
    {
        a[pos1--] = num1[i--] - '0';
    }
    while (j >= 0)
    {
        b[pos2--] = num2[j--] - '0';
    }
    pos1 = pos2 = MAX - 1;
    int rem = 0;
    int tmp;
    while (1)
    {
        if (pos1 >= 0 && pos2 >= 0)
        {
            tmp = a[pos1--] + b[pos2--];
            c[pos3--] = tmp % 10 + rem;
            rem = tmp / 10;
        }
        else
        {
            if (pos2 >= 0)
            {
                c[pos3--] = b[pos2--] + rem;
                rem = 0;
            }
            else if (pos1 >= 0)
            {
                c[pos3--] = a[pos2--] + rem;
                rem = 0;
            }
            else
                break;
        }
    }
}
void printSol()
{
    int i = 0;
    while (c[i] == 0)
        i++;
    for (; i < 100; i++)
        cout << c[i];
}
int main()
{
    string num1;
    string num2;
    cin >> num1;
    cin >> num2;
    add(num1, num2);
    printSol();
    system("pause");
}