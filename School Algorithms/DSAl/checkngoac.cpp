#include <iostream>
using namespace std;
typedef struct Stack
{
    char data;
    Stack *next;
} S;
S *top = NULL;
S *makeNode(char x)
{
    S *newNode = new S();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void push(char x)
{
    S *newNode = makeNode(x);
    if (top == NULL)
    {
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}
void pop()
{
    if (top == NULL)
        return;
    S *tmp = top->next;
    free(top);
    top = tmp;
}

bool checkEmpty()
{
    return top == NULL;
}
bool match(char a, char b)
{
    if (a == '{' && b == '}')
        return true;
    if (a == '[' && b == ']')
        return true;
    if (a == '(' && b == ')')
        return true;
    return false;
}
bool checkNgoac(string s)
{
    if (s == "")
        return false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            push(s[i]);
        else
        {
            if (s[i] == '}' || s[i] == ')' || s[i] == ']')
                if (match(top->data, s[i]))
                {
                    pop();
                    continue;
                }
                else
                    return false;
            else
                return false;
        }
    }
    if (checkEmpty())
        return true;
    else
        return false;
}
int main()
{
    int T;
    cin>>T;
    string s;
    while (T > 0)
    {
        cin >> s;
        if (checkNgoac(s))
            cout << "1";
        else
            cout << "0";
        cout << endl;
        T--;
    }
    cout << endl;
    // system("pause");
}