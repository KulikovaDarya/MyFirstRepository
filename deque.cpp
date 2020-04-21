#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAXN  1000000
typedef struct
{
    int dh, dt;
    int val[MAXN];
}deque;
void push_front(deque * d, int n)
{
    if (d -> dh < 1) d -> dh += MAXN;
    d -> val[(--d->dh) % MAXN] = n;
}
void push_back(deque * d, int n)
{
    d -> val[(d->dt++) % MAXN] = n;
}
int pop_front(deque * d)
{
    return d -> val[(d -> dh++) % MAXN];
}
int pop_back(deque * d)
{
    return d -> val[(--d->dt) % MAXN];
}
int size(deque *d)
{
    if (d->dt >= d -> dh) return (d -> dt - d -> dh) % MAXN;
    else return MAXN - (d -> dh - d -> dt) % MAXN;
}
int main()
{
    deque a;
    a.dh = 0;
    a.dt = 0;
    int n;
    string komand;
    cin >> komand;
    while (komand != "exit")
    {
        if (komand == "push_front")
        {
            cin >> n;
            push_front(&a, n);
            cout << "ok" << endl;
        }
        if (komand == "push_back")
        {
            cin >> n;
            push_back(&a, n);
            cout << "ok" << endl;
        }
        if (komand == "pop_front")
        {
            if (size(&a) == 0) cout << "error" << endl;
            else
            {
                n = pop_front(&a);
                cout << n << endl;
            }
        }
        if (komand == "pop_back")
        {
            if (size(&a) == 0) cout << "error" << endl;
            else
            {
                n = pop_back(&a);
                cout << n << endl;
            }
        }
        if (komand == "front")
        {
            if (size(&a) == 0) cout << "error" << endl;
            else cout << a.val[a.dh] << endl;
        }
        if (komand == "back")
        {
            if (size(&a) == 0) cout << "error" << endl;
            else cout << a.val[a.dt-1] << endl;
        }
        if (komand == "size")
        {
            cout << size(&a) << endl;
        }
        if (komand == "clear")
        {
           a.dt = 0;
           a.dh = 0;
           cout << "ok" << endl;
        }
        cin >> komand;
    }
    cout << "bye" << endl;
    return 0;
}
