#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
vector<ull> v(101, 0);
ull fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (v[n - 1] == 0)
        v[n - 1] = fib(n - 1);
    if (v[n - 2] == 0)
        v[n - 2] = fib(n - 2);
    return v[n - 1] + v[n - 2];
}
ull fib_2(int n)
{
    v[0] = 0;
    v[1] = 1;
    for (int i = 2; i <= n; i++)
        v[n] = v[n - 1] + v[n - 2];
    return v[n];
}
long long fib_3(int n)
{
    long long a, b, p, q;
    a = q = 1;
    b = p = 0;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            long long qq = q * q;
            q = 2 * p * q + qq;
            p = p * p + qq;
            n /= 2;
        }
        else
        {
            long long aq = a * q;
            a = b * q + aq + a * p;
            b = b * p + aq;
            n -= 1;
        }
    }
    return b;
}
int main()
{
    // int n;
    double time_spent = 0.0;
    clock_t begin = clock();
    for (int i = 0; i <= 100; i++)
        cout << fib_3(i) << endl;
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);
    system("pause");
}