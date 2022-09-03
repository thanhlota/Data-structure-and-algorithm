#include <iostream>
using namespace std;
void solving(char a, char b, char c, int n)
{
    if (n == 0)
        return;
    solving(a, c, b, n - 1);
    cout << "Move 1 place from " << a << " to " << c << endl;
    solving(b, a, c, n - 1);
}
int main()
{
    solving('A', 'B', 'C', 3);
    system("pause");
}