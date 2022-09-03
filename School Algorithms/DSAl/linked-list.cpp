#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head = new Node();
Node *node1 = new Node();
Node *node2 = new Node();
Node *node3 = new Node();
Node *node4 = new Node();
Node *last = new Node();
void printList(Node *h)
{
    Node *k = h;
    while (k != NULL)
    {
        cout << k->data << " ";
        k = k->next;
    }
}
Node *findLast(Node *h)
{
    if (h == NULL)
        return NULL;
    Node *k = h;
    while (k->next != NULL)
    {
        k = k->next;
    }
    return k;
}
Node *createNode(int x)
{
    Node *h = new Node;
    h->data = x;
    h->next = NULL;
    return h;
}
Node *insertAfter(Node *h, Node *p, int x)
{
    if (p == NULL)
        return h;
    Node *q = createNode(x);
    if (h == NULL)
        return q;
    q->next = p->next;
    p->next = q;
    return h;
}
void inserLast(Node *h, int x)
{
    Node *q = createNode(x);
    if (h == NULL)
    {
        h = q;
        return;
    }
    Node *k = h;
    while (k->next != NULL)
    {
        k = k->next;
    }
    k->next = q;
    // return h;
}
Node *locate(Node *h, int x)
{
    if (h == NULL)
        return NULL;
    Node *k = h;
    while (k != NULL)
    {
        if (k->data == x)
            return k;
        k = k->next;
    }
    return NULL;
}
Node *prev(Node *h, Node *p)
{
    if (h == NULL || p == NULL)
        return NULL;
    Node *k = h;
    if (k == p)
    {
        return NULL;
    }
    while (k != NULL)
    {
        if (k->next == p)
            return k;
        k = k->next;
    }
    return NULL;
}
Node *insertBefore(Node *h, Node *p, int x)
{
    Node *k = h;
    Node *tmp = createNode(x);
    // tmp=prev(h,p);
    if (prev(h, p) == NULL && p != NULL)
    {
        tmp->next = k;
        return tmp;
    }
    Node *u = prev(h, p);
    tmp->next = u->next;
    u->next = tmp;
    return h;
}
Node *insertBeforeRecursive(Node *h, Node *p, int x)
{
    if (h == NULL)
        return NULL;
    if (h == p)
    {
        Node *tmp = createNode(x);
        tmp->next = h;
        return tmp;
    }
    if (h->next == p)
    {
        Node *tmp = createNode(x);
        tmp->next = p;
        h->next = tmp;
    }
    else
    {
        h->next = insertBeforeRecursive(h->next, p, x);
    }
    return h;
}
Node *remove(Node *h, Node *p)
{
    if (p == NULL || h == NULL)
        return h;
    if (h == p)
    {
        Node *tmp = h->next;
        free(h);
        return tmp;
    }
    Node *k = h;
    while (k->next != p || k->next != NULL)
    {
        k = k->next;
    }
    if (k->next == NULL)
        return h;
    k->next = p->next;
    return h;
}
Node *removeRecursive(Node *h, Node *p)
{
    if (h == NULL || p == NULL)
        return h;
    if (h == p)
    {
        free(h);
        return NULL;
    }
    if (h->next == p)
    {
        h->next = p->next;
        free(p);
        return h;
    }
    h->next = removeRecursive(h->next, p);
    return h;
}
void freeList(Node *h)
{
    // if (h == NULL)
    //     return;
    // freeList(h->next);
    // free(h);
    while (h != NULL)
    {
        Node *tmp = h->next;
        free(h);
        h = h->next;
    }
}
int main()
{
    head->data = 1;
    node1->data = 2;
    node2->data = 3;
    node3->data = 4;
    node4->data = 5;
    last->data = 6;
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = last;
    last->next = NULL;
    // head = insertBefore(head, head, 7);
    // head = removeRecursive(head, node3);
    printList(head);
    cout << endl;
    inserLast(head, 10);
    printList(head);
    system("pause");
}