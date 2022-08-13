#include <stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x){
    if(top == MAX_SIZE - 1){
        printf("Error: stack Overflow\n");
        return;
    }
    A[++top] = x;
}

void Pop(){
    if(top == -1){
        printf("Error: stack is Empty\n");
        return;
    }
    top--;
}


void Top(){
    return A[top];
}

void Print(){
    printf("Stack: ");
    for(int i = 0; i <= top; i++){
        printf("%d: %d\t", i, A[i]);
    }
    printf("\n");
}

int main()
{
    Push(4);Print();
    Push(5);Print();
    Push(8);Print();
    Pop();Print();
    Push(66);Print();
    Push(7);Print();
    Pop();Print();
    Push(1);Print();

    return 0;
}
