/*Cho 2 so nguyen duong X va Y
Tim tat ca cac so nguyen duong nho hon hoac bang X ma tong cac chu so dung bang Y
*/
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull faster_cnt(ull x, ull y)
{
    if (y == 0 && x >= 0)
        return 1;
    if (y > x)
        return 0;
    ull sum = 0;
    ull t = (y < 9) ? y : 9;
    for (ull i = 0; i <= t; i++)
    {
        sum += faster_cnt((x - i) / 10, y - i);
    }
    return sum;
}
ull slow_cnt(ull x, ull y)
{
    ull sum = 0;
    for (ull i = 1; i <= x; i++)
    {
        ull s = 0;
        ull tmp = i;
        while (tmp != 0)
        {
            s += tmp % 10;
            tmp = tmp / 10;
        }
        if (s == y)
            sum += 1;
    }
    return sum;
}
int main()
{
    // 40051495
    double time_spent = 0.0;
    clock_t begin = clock();
    cout << faster_cnt(1000000000, 45) << endl;
    // cout << slow_cnt(1000000000, 45);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);
    system("pause");
}
