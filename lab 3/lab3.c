#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;


void insert(int item) {
    if (rear == MAX_SIZE - 1) {
        printf("\nQUEUE OVERFLOW\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("\nInserted %d\n", item);
    }
}


void delete_item() {
    if (front == -1 || front > rear) {
        printf("\nQUEUE EMPTY\n");
    } else {
        printf("\nDeleted element: %d\n", queue[front]);
        front++;
        if (front > rear) {

            front = -1;
            rear = -1;
        }
    }
}


void display() {
    if (front == -1) {
        printf("\nQUEUE EMPTY\n");
    } else {
        int i;
        printf("\nQueue elements are: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}


int main() {
    int choice, item;

    while (1) {
        printf("\n--- Queue Operations Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                delete_item();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
