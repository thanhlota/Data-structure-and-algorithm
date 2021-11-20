#include <iostream>
using namespace std;
int test(){
   int x=5;
   int *p=&x;
   return x;
}
int main()
{  
   cout<<test();
   system("pause");
}