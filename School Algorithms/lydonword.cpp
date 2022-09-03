// #include "square1.h"
// // square.h is also included once here
// #include <iostream>

// int main()
// {
//     std::cout << "a square has " << getSquareSides() << " sides\n";
//     std::cout << "a square of length 5 has perimeter length " << getSquarePerimeter(5) << '\n';
//     system("pause");
//     return 0;

// }
#include <iostream>
using namespace std;
void lyndon(string s)
{
     int n = (int)s.length();
     int i = 0;
     while (i < n)
     {
          int j = i + 1, k = i;
          while (j < n && s[k] <= s[j])
          {
               if (s[k] < s[j])
                    k = i;
               else
                    ++k;
               ++j;
          }
          while (i <= k)
          {
               cout << s.substr(i, j - k) << ' ';
               i += j - k;
          }
     }
     cout << endl;
}

int main()
{
     lyndon("SIXMIXEDPIXIESSIFTSIXTYPIXIEDUSTBOXES");
     system("pause");
     return 0;
     return 0;
     return 0;
}
