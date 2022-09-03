#include <iostream>
using namespace std;
int main()
{
    int arr[1000], cnt;
    int res[1000];
    arr['a']=arr['d']=arr['g']=arr['j']=arr['m']=arr['p'] = 1;
    arr['b']=arr['e']=arr['h']=arr['k']=arr['n']=arr['q'] = 2;
    arr['c']=arr['f']=arr['i']=arr['l']=arr['o']=arr['r'] = 3;
    arr['s'] = 4;
    arr['t'] = 1;
    arr['u'] = 2;
    arr['v'] = 3;
    arr['w'] = 1;
    arr['x'] = 2;
    arr['y'] = 3;
    arr['z'] = 4;
    arr[' '] = 1;
    int n;
    cin >> n;
    int k = 0;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        string tmp;
        getline(cin, tmp);
        for (int j = 0; j < tmp.length(); j++)
        {
            cnt += arr[tmp[j]];
        }
        res[k++] = cnt;
        // cin.ignore();
    }
    for (int i = 0; i < n; i++)
        cout << "Case #" << i + 1 << ": " << res[i] << endl;
    system("pause");
}