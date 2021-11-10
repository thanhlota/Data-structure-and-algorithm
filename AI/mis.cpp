#include <iostream>
using namespace std;
int main()
{
   int x, y, z;
   cout << "Enter three integers:" << endl;
   cin >> x;
   cin >> y;
   cin >> z;
   int *ptr1, *ptr2, *ptr3;
   ptr1 = &x;
   ptr2 = &y;
   ptr3 = &z;
   cout << "The three integers are:" << endl;
   cout << "x = " << *ptr1 << endl;
   cout << "y = " << *ptr2 << endl;
   cout << "z = " << *ptr3 << endl;
}