#include <iostream>
using namespace std;
const int N = 10000;
int n = 10;
int a[] = {4 ,3, 2, 3, 6, 1, 5, 4, 9, 7};
int nmax = 1;
int maximus = INT_MIN;
int res[N];
int myIndex[N]{-1};
int trace;
/////////////////////////////
int tmp[N];
// solution 1
void Try(int k)
{
    for (int i = res[k - 1] + 1; i < n; i++)
    {
        if (a[i] > a[res[k - 1]])
        {
            nmax += 1;
            res[k] = i;
            if (nmax > maximus)
            {
                maximus = nmax;
                trace = res[0];
                myIndex[res[k - 1]] = i;
                myIndex[i] = -1;
            }
            Try(k + 1);
            nmax -= 1;
        }
    }
}
void trace_out()
{
    int k = trace;
    cout << a[trace] << " ";
    while (1)
    {
        if (myIndex[k] == -1)
            break;
        k = myIndex[k];
        cout << a[k] << " ";
    }
}
// int max_arr(int k)
// {
//     for (int i = 0; i < k; i++)
//         for (int j = i + 1; j <= k; j++)
//         {
//             if (tmp[j] > tmp[i])
//             {
//                 int h = tmp[i];
//                 tmp[i] = tmp[j];
//                 tmp[j] = h;
//             }
//         }
// }
// solution 2
void algo2()
{
    int maxi=1;
    tmp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        tmp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
                tmp[i] = max(tmp[i], tmp[j] + 1);
        }
        maxi=max(maxi,tmp[i]);
    }
    cout<<maxi;

}
int main()
{
    // for (int i = 0; i < n - 1; i++)
    // {
    //     res[0] = i;
    //     Try(1);
    // }
    // trace_out();
    // cout << endl;
    // cout << maximus << endl;
    algo2();
    system("pause");
}

/*
bool found =false;
void find(int s[],start,end,x){
    if(start==end){
        if(s[start]==x) found=true;
        return;
    }
    else{
    int mid=(start+end)/2;
    if(s[mid]==x) found=true;
    else if(s[mid]>x) find(s,mid+1,end,x);
    else find(s,start,mid,x);
    }
}
*/