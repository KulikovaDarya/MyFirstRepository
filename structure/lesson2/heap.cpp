#include <stdio.h>
nt Sift_Down(int a[], int i, int n)
{
    int left, right, t, largest, f;
    while(i < n)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        largest = i;
        f = 0;
        if (left < n && a[left] > a[largest]) largest = left;
        if (right < n && a[right] > a[largest]) largest = right;
        if (largest == i) break;

        t = a[i];
        a[i] = a[largest];
        a[largest] = t;
        i = largest;
    }
    return i;
}
int Sift_Up(int a[], int i)
{
    int t, parent = (i - 1)/2;
    while (a[i] > a[parent])
    {
        t = a[i];
        a[i] = a[parent];
        a[parent] = t;
        i = parent;
    }
    return i;
}
void Build_Heap2(int a[], int N)
{
    for (int i = (N-1)/2; i >= 0; i--) Sift_Down(a, i, N);
}
