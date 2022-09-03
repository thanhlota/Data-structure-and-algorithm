////////// an implementation using the knowledge of tree structure(slow version)
#include <bits/stdc++.h>
using namespace std;
#include <iostream>
using namespace std;
struct Node
{
    string id;
    Node *leftMostChild; // Con tro tro toi node con trai nhat
    Node *rightSibling;  // Con tro tro toi node anh em ben phai
};
Node *root;
Node *makeNode(string v)
{
    Node *p = new Node;
    p->id = v;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}
Node *Find(Node *r, string v)
{
    if (r->leftMostChild == NULL)
        return NULL;
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        if (p->id == v)
            return p;
        p = p->rightSibling;
    }
    return NULL;
}
Node *parent(Node *r, Node *p)
{
    if (r == NULL)
        return NULL;
    Node *k = r->leftMostChild;
    if (k == p)
        return r;
    while (k != NULL)
    {
        Node *tmp = parent(k, p);
        if (tmp != NULL)
            return tmp;
        k = k->rightSibling;
        if (k == p)
            return r;
    }
    return NULL;
}

Node *insert(Node *parent, string v)
{
    Node *child = makeNode(v);
    if (parent->leftMostChild == NULL)
    {
        parent->leftMostChild = child;
        return child;
    }
    Node *p = parent->leftMostChild;
    while (p->rightSibling != NULL)
        p = p->rightSibling;
    p->rightSibling = child;
    return child;
}
void print(stack<string> q)
{
    while (!q.empty())
    {
        cout << q.top();
        q.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string command, path;
    root = makeNode("/");
    Node *tmp = root;
    while (n > 0)
    {
        cin >> command;
        if (command == "cd")
        {
            cin >> path;
            string k;
            if (path[0] == '/')
                tmp = root;
            else
            {
                k += path[0];
                if (path.length() == 1)
                {
                    Node *x = Find(tmp, k);
                    if (x == NULL)
                        tmp = insert(tmp, k);
                    else
                        tmp = x;
                    continue;
                }
            }
            for (int i = 1; i < path.length(); i++)
            {
                if (path[i] != '/')
                    k += path[i];
                if (path[i] == '/' || i == (path.length() - 1))
                {
                    if (k == "..")
                        tmp = parent(root, tmp);
                    else
                    {
                        Node *x = Find(tmp, k);
                        if (x == NULL)
                            tmp = insert(tmp, k);
                        else
                            tmp = x;
                    }
                    k = "";
                }
            }
        }
        else
        {
            Node *k = tmp;
            stack<string> s;
            if (tmp == root)
                cout << '/';
            else
            {
                s.push("/");
                s.push(tmp->id);
                s.push("/");
                k = parent(root, k);
                while (k != root)
                {
                    s.push(k->id);
                    s.push("/");
                    k = parent(root, k);
                }
                print(s);
            }
            cout << endl;
        }
        n--;
    }
    // system("pause");
}