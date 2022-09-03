#include <bits/stdc++.h>
using namespace std;
struct State
{
    int x, y;
    State *next;
    State *parent;
    State(int ix, int iy)
    {
        x = ix;
        y = iy;
        next = NULL;
        parent = NULL;
        // printf("constructor state %d,%d\n",x,y);
    }
};

struct Queue
{
    State *head;
    State *tail;
    Queue()
    {
        head = NULL;
        tail = NULL;
        // printf("constructor queue\n");
    }
    void push(State *s)
    {
        if (empty())
        {
            head = s;
            tail = s;
            return;
        }
        tail->next = s;
        tail = s;
    }
    State *pop()
    {
        if (empty())
            return NULL;
        State *tmp = head;
        head = head->next;
        if (head == NULL)
            tail = NULL;
        return tmp;
    }
    bool empty()
    {
        return head == NULL && tail == NULL;
    }
    void print()
    {
        if (empty())
        {
            printf("EMPTY\n");
            return;
        }
        printf("head = (%d,%d), tail = (%d,%d): ", head->x, head->y, tail->x, tail->y);
        for (State *p = head; p != NULL; p = p->next)
        {
            printf("(%d,%d) ", p->x, p->y);
        }
        printf("\n");
    }
};
Queue Q;
bool visited[1000][1000]{false}; // visited[x][y] = true co nghia (x,y) da duoc xet den
State *target;
State *start;
int a, b, c;
bool finalState(State *s)
{
    return s->x == c || s->y == c;
}
bool fillJug1(State *s)
{
    if (visited[a][s->y])
        return false;
    State *newState = new State(a, s->y);
    newState->parent = s;
    Q.push(newState);
    visited[newState->x][newState->y] = true;
    if (finalState(newState))
    {
        target = newState;
        return true;
    }
    return false;
}
bool fillJug2(State *s)
{
    if (visited[s->x][b])
        return false;
    State *newState = new State(s->x, b);
    newState->parent = s;
    Q.push(newState);
    visited[newState->x][newState->y] = true;
    if (finalState(newState))
    {
        target = newState;
        return true;
    }
    return false;
}
bool pourJug1toJug2(State *s)
{
    if (s->y == b)
        return false;
    if ((s->x + s->y) > b)
    {
        if (visited[s->x + s->y - b][b])
            return false;
        State *newState = new State((s->x + s->y - b), b);
        visited[s->x + s->y - b][b] = true;
        Q.push(newState);
        newState->parent = s;
        if (finalState(newState))
        {
            target = newState;
            return true;
        }
        return false;
    }
    else
    {
        if (visited[0][s->x + s->y])
            return false;
        State *newState = new State(0, s->x + s->y);
        visited[0][s->x + s->y] = true;
        Q.push(newState);
        newState->parent = s;
        if (finalState(newState))
        {
            target = newState;
            return true;
        }
        return false;
    }
}
void printSol(State *tmp)
{
    if (tmp != NULL)
    {
        printSol(tmp->parent);
        cout << "(" << tmp->x << "," << tmp->y << ")" << endl;
    }
}
bool pourJug2toJug1(State *s)
{
    if (s->x == a)
        return false;
    if ((s->x + s->y) > a)
    {
        if (visited[a][s->x + s->y - a])
            return false;
        State *newState = new State(a, s->x + s->y - a);
        visited[a][s->x + s->y - a] = true;
        Q.push(newState);
        newState->parent = s;
        if (finalState(newState))
        {
            target = newState;
            return true;
        }
        return false;
    }
    else
    {
        if (visited[s->x + s->y][0])
            return false;
        State *newState = new State(s->x + s->y, 0);
        visited[s->x + s->y][0] = true;
        Q.push(newState);
        newState->parent = s;
        if (finalState(newState))
        {
            target = newState;
            return true;
        }
        return false;
    }
}
bool emptyJug1(State *s)
{
    if (visited[0][s->y])
        return false;
    State *newState = new State(0, s->y);
    visited[0][s->y] = true;
    Q.push(newState);
    newState->parent = s;
    if (finalState(newState))
    {
        target = newState;
        return true;
    }
    return false;
}
bool emptyJug2(State *s)
{
    if (visited[s->x][0])
        return false;
    State *newState = new State(s->x, 0);
    visited[s->x][0] = true;
    Q.push(newState);
    newState->parent = s;
    if (finalState(newState))
    {
        target = newState;
        return true;
    }
    return false;
}
void process()
{
    State *start = new State(0, 0);
    Q.push(start);
    visited[0][0] = true;
    target = NULL;
    State *tmp;
    while (!Q.empty())
    {
        tmp = Q.pop();
        if (fillJug1(tmp))
        {

            break;
        }
        if (fillJug2(tmp))
        {

            break;
        }
        if (pourJug1toJug2(tmp))
        {

            break;
        };
        if (pourJug2toJug1(tmp))
        {

            break;
        };
        if (emptyJug1(tmp))
        {

            break;
        };
        if (emptyJug2(tmp))
        {

            break;
        };
    }
    if (Q.empty())
        cout << "No solution!" << endl;
    else
        printSol(target);
}
int main()
{
    a = 6, b = 8, c = 4;
    process();
    system("pause");
}