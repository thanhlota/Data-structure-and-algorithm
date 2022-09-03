#include <iostream>
using namespace std;
struct BNode
{
    int id;
    BNode *leftChild;  // con trỏ đến nút con trái
    BNode *rightChild; // con trỏ đến nút con phải
};
void preOrder(BNode *r)
{
    if (r == NULL)
        return;
    cout << r->id;
    preOrder(r->leftChild);
    preOrder(r->rightChild);
}
void postOrder(BNode *r)
{
    if (r == NULL)
        return;
    postOrder(r->leftChild);
    postOrder(r->rightChild);
    cout << r->id;
}
void inOrder(BNode *r)
{
    if (r == NULL)
        return;
    inOrder(r->leftChild);
    cout << r->id;
    inOrder(r->rightChild);
}
int count(BNode *r)
{
    if (r == NULL)
        return 0;
    return 1 + count(r->leftChild) +
           count(r->rightChild);
}
int main()
{
    
}