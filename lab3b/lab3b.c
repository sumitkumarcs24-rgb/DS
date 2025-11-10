#include <stdio.h>
#include <stdbool.h>
#define size 20

int N[size];
int front = -1, rear = -1;

int isFull() {
    if ((rear + 1) % size == front)
        return true;
    else
        return false;
}

int isEmpty() {
    if (front == -1)
        return true;
    else
        return false;
}

void enqueue(int x) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    else if (isEmpty()) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % size;
    }
    N[rear] = x;
    printf("%d inserted into queue\n", x);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d deleted from queue\n", N[front]);
    if (front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % size;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:");
    int i = front;
    while (true) {
        printf(" %d", N[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (true) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}