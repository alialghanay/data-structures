#include <stdio.h>
#define MAX_SIZE 10
int A[MAX_SIZE];
int front = -1, rear = -1;

void Enqueue(int x){
    if((rear + 1) % MAX_SIZE == front){
        printf("Error: queue Overflow\n");
        return;
    }else if (front == -1 && rear == -1){
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    A[rear] = x;
}

void Dequeue(){
    if(front == rear){
        front = -1, rear = -1;
        printf("Error: queue is Empty\n");
        return;
    }
    front = (front+1)%MAX_SIZE;
}


void Print(){
    printf("queue: ");
    if(front < rear){
     for(int i = front; i <= rear; i++){
        printf("%d: %d\t", i, A[i]);
        }
    }else {
        for(int i = front; i != rear; i=(i+1)%MAX_SIZE){
        printf("%d: %d\t", i, A[i]);
        }
    }
    printf("\n");
    printf("Front: %d\n", front);
    printf("Rear: %d\n", rear);
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
    Dequeue();Print();
    Enqueue(9);Print();
    Enqueue(10);Print();
    Enqueue(66);Print();
    Enqueue(88);Print();
    Enqueue(13);Print();
    Enqueue(99);Print();
    printf("rear: %d", A[rear]);
    Enqueue(100);Print();
    return 0;
}
