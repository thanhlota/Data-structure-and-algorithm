#include <iostream>
using namespace std;
struct Node
{
    int id;
    Node *leftMostChild; // Con tro tro toi node con trai nhat
    Node *rightSibling;  // Con tro tro toi node anh em ben phai
};

Node *root;

Node *makeNode(int v)
{
    Node *p = new Node;
    p->id = v;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}
Node *Find(Node *r, int v)
{
    if (r == NULL)
        return NULL;
    if (r->id == v)
        return r;
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        Node *p = Find(p, v);
        if (p != NULL)
            return p;
        else
            p = p->rightSibling;
    }
    return NULL;
}
void preOrder(Node *r)
{
    if (r == NULL)
        return;
    cout << r->id << " ";
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        preOrder(p);
        p = p->rightSibling;
    }
}
void inOrder(Node *r)
{
    if (r == NULL)
        return;
    Node *p = r->leftMostChild;
    inOrder(p);
    cout << r->id << " ";
    if (p != NULL)
        p = p->rightSibling;
    while (p != NULL)
    {
        inOrder(p);
        p = p->rightSibling;
    }
}
void postOrder(Node *r)
{
    if (r == NULL)
        return;
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        postOrder(p);
        p = p->rightSibling;
    }
    cout << r->id;
}
int count(Node *r)
{
    if (r == NULL)
        return 0;
    int cnt = 1;
    Node *p = r->leftMostChild;
    cnt += count(p);
    if (p != NULL)
        p = p->rightSibling;
    while (p != NULL)
    {
        cnt += count(p);
        p = p->rightSibling;
    }
    return cnt;
}
int countLeaves(Node *r)
{
    int cnt = 0;
    Node *p = r->leftMostChild;
    if (p == NULL)
        return 1;
    while (p != NULL)
    {
        cnt += countLeaves(p);
        p = p->rightSibling;
    }
    return cnt;
}
int height(Node *p)
{
    if (p == NULL)
        return 0;
    Node *k = p->leftMostChild;
    int maxH = 0;
    while (k != NULL)
    {
        int h = height(k);
        maxH = max(maxH, h);
        k = k->rightSibling;
    }
    return maxH + 1;
}
int d = 0;
int depth(Node *r, Node *p)
{
    if (r == NULL)
    {
        d = 0;
        return 0;
    }
    if (r == p)
    {
        d = 1;
        return 1;
    }
    Node *k = r->leftMostChild;
    while (k != NULL)
    {
        int tmp = depth(k, p);
        if (tmp > 0)
            return d + tmp;
        k = k->rightSibling;
    }
    return 0;
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
void insert(int u, int v)
{
    // tao 1 nut co id = v, chen vao cuoi DS nut con cua nut co id = u
    Node *p = Find(root, u);
    if (p == NULL)
        return;
    Node *tmp = p->leftMostChild;
    if (tmp == NULL)
    {
        p->leftMostChild = makeNode(v);
        return;
    }
    while (tmp->rightSibling != NULL)
        tmp = tmp->rightSibling;
    tmp->rightSibling = makeNode(v);
}
void printTree(Node *r)
{
    if (r == NULL)
        return;
    printf("%d: ", r->id); // in ra id cua mut goc r
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        printf("%d ", p->id); // in ra id cua cac nut con cua r tu trai qua phai
        p = p->rightSibling;
    }
    printf("\n");
    // goi de quy de in ra cac cay con cua r
    p = r->leftMostChild;
    while (p != NULL)
    {
        printTree(p); // goi de quy de in ra cay con co goc p
        p = p->rightSibling;
    }
}
void freeTree(Node *r)
{
    if (r == NULL)
    {
        return;
    }
    Node *p = r->leftMostChild;
    Node *np = p->rightSibling;
    while (p != NULL)
    {
        freeTree(p);
        p = np;
        if (np->rightSibling == NULL)
            np = np->rightSibling;
    }
    free(r);
}
int main()
{
    Node *r = makeNode(1);
    Node *node1 = makeNode(2);
    Node *node2 = makeNode(3);
    Node *node3 = makeNode(4);
    Node *node4 = makeNode(5);
    Node *node5 = makeNode(6);
    Node *node6 = makeNode(7);
    r->leftMostChild = node1;
    node1->rightSibling = node2;
    node1->leftMostChild = node3;
    node3->rightSibling = node4;
    node4->leftMostChild = node5;
    postOrder(r);
    system("pause");
}