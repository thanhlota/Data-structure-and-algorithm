#include <iostream>
using namespace std;
int main()
{
    int pos = 0;
    int n1, n2, a[1000], b[1000];
    int check[1000]{0};
    int r[1000]{0};
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }
    cin >> n2;
    int cnt = 0;
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
        if (r[b[i]] == 0)
        {
            r[b[i]] = 1;
            cnt++;
        }
    }
    for (int i = 0; i < n1; i++)
    {
        if (r[a[i]] == 1)
        {
            if (check[a[i]] == 0)
            {
                check[a[i]] = 1;
                pos++;
                if (pos == cnt)
                    break;
            }
        }
    }
    if (pos == cnt)
        cout << "1";
    else
        cout << "0";
    // system("pause");
}