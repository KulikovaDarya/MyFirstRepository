#include <stdio.h>
#define MAXN  1000
typedef struct queue
{
    int first, size;
    char data[MAXN];
} queue;
void queue_init(queue * q)
{
    q -> size = 0;
    q -> first = 0;
}
void queue_add(queue * q, int x)
{
    q -> data[(q -> first + q -> size) % MAXN] = x;
    q -> size++;
}
void queue_drop(queue *q)
{
    q -> first++;
    if ( q-> first == MAXN) q -> first = 0;
    q -> size--;
}
char queue_first(queue *q)
{
    return q -> data[q -> first];
}
int queue_isempty(queue * q)
{
    if (q -> size == 0) return 1;
    else return 0;
}
int main()
{
    queue q1;
    queue_init(&q1);
    queue_add(&q1,10);
    queue_add(&q1,20);
    printf("%d\n",queue_first(&q1)); // 10
    queue_drop(&q1);
    if(!queue_isempty(&q1))
        printf("%d\n",queue_first(&q1)); // 20
}
