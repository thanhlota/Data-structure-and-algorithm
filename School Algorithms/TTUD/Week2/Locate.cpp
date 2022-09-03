#include <iostream>
#include <vector>
#define vt vector<pair<int, int>>
using namespace std;
int arr[3000][3000]{0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, row, column;
    cin >> T;
    int tmp;
    for (int i = 0; i < T; i++)
    {
        int maximus = 0;
        vt pre, post;
        cin >> row;
        cin >> column;
        for (int j = 0; j < row; j++)
            for (int k = 0; k < column; k++)
            {
                cin >> tmp;
                if (tmp)
                    pre.push_back({j, k});
            }
        for (int j = 0; j < row; j++)
            for (int k = 0; k < column; k++)
            {
                cin >> tmp;
                if (tmp)
                    post.push_back({j, k});
            }
        int presize = pre.size();
        int postsize = post.size();
        for (int j = 0; j < presize; j++)
            for (int k = 0; k < postsize; k++)
            {
                int a = post[k].first - pre[j].first + 2000;
                int b = post[k].second - pre[j].second + 2000;
                ++arr[a][b];
            }
        for (int j = 0; j < 3000; j++)
            for (int k = 0; k < 3000; k++)
            {
                if (arr[j][k])
                    maximus = (arr[j][k] > maximus) ? arr[j][k] : maximus;
            }
        cout << maximus << "\n";
    }
    // cout.flush();
    system("pause");
}