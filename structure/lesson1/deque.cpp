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
