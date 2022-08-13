#include <stdio.h>
#define MAX_SIZE 10
int A[MAX_SIZE];
int front = -1, rear = -1;

void Enqueue(int x){
    if(rear == MAX_SIZE - 1 && front == 0){
        printf("Error: queue Overflow\n");
        return;
    }else if (front == -1 && rear == -1){
        front++;
    }else if(rear == MAX_SIZE - 1 && front > 0){
        for(int i = front; i <= rear; i++){
            A[i - front] = A[i];
        }
        rear -= front;
        front = 0;
    }
    rear++;
    A[rear] = x;
}

void Dequeue(){
    if(front == rear){
        front = -1, rear = -1;
    }else front++;
}


void Print(){
    printf("queue: ");
    for(int i = front; i <= rear; i++){
        printf("%d: %d\t", i, A[i]);
    }
    printf("\n");
}

int main()
{
    Enqueue(1);Print();
    Enqueue(2);Print();
    Enqueue(3);Print();
    Dequeue();Print();
    Enqueue(4);Print();
    Enqueue(5);Print();
    Dequeue();Print();
    Enqueue(6);Print();
    Enqueue(7);Print();
    Enqueue(8);Print();
    Enqueue(9);Print();
    Enqueue(10);Print();
    Enqueue(11);Print();
    Enqueue(12);Print();
    Enqueue(13);Print();
    return 0;
}
