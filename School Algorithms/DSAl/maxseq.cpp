#include <iostream>
#define MAX 1000
using namespace std;
int a[MAX]{3, 5, -7, 2, 3, -1, 4, 3};
int length = 8;
int start, finish, sum, maximus = INT_MIN;
int maxleft(int, int);
int maxright(int, int);
int seq(int, int);
void algo1()
{
    for (int i = 0; i < length; i++)
    {
        sum = 0;
        for (int j = i; j < length; j++)
        {
            sum += a[j];
            if (sum > maximus)
            {
                start = i;
                finish = j;
                maximus = sum;
            }
        }
    }
    cout << "Max= " << maximus << endl;
    for (int k = start; k <= finish; k++)
    {
        cout << a[k] << " ";
    }
}
int maxseq(int c, int b)
{
    if (c == b)
        return a[c];
    int left = maxseq(c, (b + c) / 2);
    int right = maxseq((b + c) / 2 + 1, b);
    int all = maxleft(c, (b + c) / 2) + maxright((b + c) / 2 + 1, b);
    int sum1 = (left > right) ? ((left > all) ? left : all) : ((right > all) ? right : all);
    return sum1;
}
int maxleft(int c, int b)
{
    int ml = INT_MIN;
    int sum1 = 0;
    for (int i = b; i >= c; i--)
    {
        sum1 += a[i];
        if (ml < sum1)
            ml = sum1;
    }
    return ml;
}
int maxright(int c, int b)
{
    int mr = INT_MIN;
    int sum2 = 0;
    for (int i = c; i <= b; i++)
    {
        sum2 += a[i];
        if (mr < sum2)
            mr = sum2;
    }
    return mr;
}
void algo2()
{
    maximus = maxseq(0, 7);
    cout << "Max= " << maximus;
}
void algo3()
{
    int tres = a[0];
    maximus = tres;
    for (int i = 1; i < length; i++)
    {
        if (tres < 0)
            tres = a[i];
        else
            tres += a[i];
        if (maximus < tres)
            maximus = tres;
    }
    cout << "Max= " << maximus;
}
int main()
{
    algo3();
    system("pause");
}