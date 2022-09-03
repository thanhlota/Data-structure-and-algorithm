#include <bits/stdc++.h>
using namespace std;
long long maxPrimeFactors(long long n)
{
    // Initialize the maximum prime factor
    // variable with the lowest one
    long long maxPrime = -1;

    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        maxPrime = 2;
        n >>= 1; // equivalent to n /= 2
    }
    // n must be odd at this point
    while (n % 3 == 0)
    {
        maxPrime = 3;
        n = n / 3;
    }
    while (n % 5 == 0)
    {
        maxPrime = 5;
        n = n / 5;
    }
    // now we have to iterate only for integers
    // who does not have prime factor 2 and 3
    for (int i = 7; i <= sqrt(n); i += 30)
    {
        while (n % i == 0)
        {
            maxPrime = i;
            n = n / i;
        }
        while (n % (i + 4) == 0)
        {
            maxPrime = i + 4;
            n = n / (i + 4);
        }
        while (n % (i + 6) == 0)
        {
            maxPrime = i + 6;
            n = n / (i + 6);
        }
        while (n % (i + 10) == 0)
        {
            maxPrime = i + 10;
            n = n / (i + 10);
        }
        while (n % (i + 12) == 0)
        {
            maxPrime = i + 12;
            n = n / (i + 12);
        }
        while (n % (i + 16) == 0)
        {
            maxPrime = i + 16;
            n = n / (i + 16);
        }
        while (n % (i + 22) == 0)
        {
            maxPrime = i + 22;
            n = n / (i + 22);
        }
    }
    // This condition is to handle the case
    // when n is a prime number greater than 4
    if (n > 6)
        maxPrime = n;
    return maxPrime;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    long long n;
    // cin >> T;
    // while (T > 0)
    // {
    //     cin >> n;
    //     cout << maxPrimeFactors(n) << endl;
    //     T -= 1;
    // }
    cout << maxPrimeFactors(99) << endl;
    system("pause");
    return 0;
}