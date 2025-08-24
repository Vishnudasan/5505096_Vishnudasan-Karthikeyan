#include <stdio.h>

#define MAX 100000

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

void push1(int x) {
    s1[++top1] = x;
}

void push2(int x) {
    s2[++top2] = x;
}

int pop1() {
    return s1[top1--];
}

int pop2() {
    return s2[top2--];
}

int peek2() {
    return s2[top2];
}

int isEmpty1() {
    return top1 == -1;
}

int isEmpty2() {
    return top2 == -1;
}

void enqueue(int x) {
    push1(x);
}

void shiftStacks() {
    if (isEmpty2()) {
        while (!isEmpty1()) {
            push2(pop1());
        }
    }
}

void dequeue() {
    shiftStacks();
    if (!isEmpty2()) pop2();
}

void printFront() {
    shiftStacks();
    if (!isEmpty2()) printf("%d\n", peek2());
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int type, x;
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d", &x);
            enqueue(x);
        } else if (type == 2) {
            dequeue();
        } else if (type == 3) {
            printFront();
        }
    }
    return 0;
}
