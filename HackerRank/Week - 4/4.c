#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


#define MAX 100000

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int idx) {
    while (idx > 0) {
        int p = (idx - 1) / 2;
        if (heap[idx] < heap[p]) {
            swap(&heap[idx], &heap[p]);
            idx = p;
        } else break;
    }
}

void heapifyDown(int idx) {
    while (1) {
        int l = 2 * idx + 1, r = 2 * idx + 2, s = idx;
        if (l < size && heap[l] < heap[s]) s = l;
        if (r < size && heap[r] < heap[s]) s = r;
        if (s != idx) {
            swap(&heap[idx], &heap[s]);
            idx = s;
        } else break;
    }
}

void insert(int x) {
    heap[size] = x;
    heapifyUp(size);
    size++;
}

void deleteval(int x) {
    int i;
    for (i = 0; i < size; i++) if (heap[i] == x) break;
    heap[i] = heap[size - 1];
    size--;
    heapifyDown(i);
    heapifyUp(i);
}

int getMin() {
    return heap[0];
}

int main() {
    int q; 
    scanf("%d", &q);
    while (q--) {
        int t, v;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d", &v);
            insert(v);
        } else if (t == 2) {
            scanf("%d", &v);
            deleteval(v);
        } else {
            printf("%d\n", getMin());
        }
    }
    return 0;
}
