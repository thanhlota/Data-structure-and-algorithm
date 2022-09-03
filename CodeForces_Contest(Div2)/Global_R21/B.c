#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int value;
    Node *nextNode;
} Node;
Node *h;
void duyetdanhsach(Node *h)
{
    Node *p = h;
    while (p != NULL)
    {
        printf("%d", p->value);
        p = p->nextNode;
    }
}
void freeAll(Node *h)
{
    Node *tmp;
    while (h != NULL)
    {
        tmp = h->nextNode;
        free(h);
        h = tmp;
    }
}
Node *makeNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = v;
    newNode->nextNode = NULL;
    return newNode;
}
Node *inserLast(Node *h, int v)
{
    Node *newNode = makeNode(v);
    if (h == NULL)
    {
        h = newNode;
        return h;
    }
    Node *p = h;
    while (p->nextNode != NULL)
    {
        p = p->nextNode;
    }
    p->nextNode = newNode;
    return h;
}
Node *insertHead(Node *h, int v)
{
    Node *newNode = makeNode(v);
    newNode->nextNode = h;
    h = newNode;
    return h;
}
Node *insertAfter(Node *h, Node *p, int v)

{
    Node *t = makeNode(v);
    if (h == NULL)
    {
        return t;
    }
    if (p == NULL)
    {
        return h;
    }
    t->nextNode = p->nextNode;
    p->nextNode = t;
    return h;
}
Node *locate(Node *h, int x)
{
    if (h == NULL)
        return NULL;
    Node *p = h;
    while (p != NULL)
    {
        if (p->value == x)
            return p;
        p = p->nextNode;
    }
    return NULL;
}
Node *prev(Node *h, Node *p)
{
    if (h == NULL)
        return NULL;
    if (h == p)
    {
        return NULL;
    }
    Node *t = h;
    while (t->nextNode != NULL)
    {
        if (t->nextNode == p)
            return t;
        t = t->nextNode;
    }
    return NULL;
}
Node *insertAt(Node *h, Node *p, int v)
{
    if (p == NULL)
        return h;
    Node *t = prev(h, p);
    Node *newNode = makeNode(v);
    if (t == NULL)
    {
        if (h == NULL)
        {
            return newNode;
        }
        newNode->nextNode = h;
        return newNode;
    }
    newNode->nextNode = t->nextNode;
    t->nextNode = newNode;
    return h;
}
Node *remove(Node *h, Node *p)
{
    if (h == NULL || p == NULL)
        return NULL;
    Node *t = h;
    if (t == p)
    {
        Node *tmp = t->nextNode;
        free(t);
        return tmp;
    }
    Node *tmp = prev(h, p);
    tmp->nextNode = p->nextNode;
    free(p);
    return h;
}

int main()
{
}