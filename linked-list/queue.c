#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node* next;
};

// front pointer
struct node* Front = NULL;
// rear pointer
struct node* Rear = NULL;


// inserting new node in the queue with item
void enqueue(int value);
// deleting node from the queue
void dequeue(void);
// deleting whole queue
void deletequeue(void);
// printing whole queue
void printqueue(void);
// searching for node in the queue with value
struct node* Search(int x);

int main(void)
{
    enqueue(13);
    enqueue(2);
    enqueue(11);
    enqueue(9);
    printqueue();
    enqueue(20);
    printqueue();
    dequeue();
    printqueue();
    if(Search(20) == NULL)
    {
     printf("searching : there is no node with this value \n\n");
    }else printf("searching : node is existing \n\n");
    deletequeue();
    printqueue();
    printf("\n bye! \n");
    return 0;
}

void enqueue(int value)
{
    struct node* nextnode = malloc(sizeof(struct node));
    nextnode->data = value;
    nextnode->next = NULL;
    if(Front == NULL)Front = nextnode;
        else Rear->next = nextnode;
    Rear = nextnode;
}


void dequeue(void)
{
    struct node* temp;
    temp = Front;
    Front = Front->next;
    free(temp);
}


void deletequeue(void)
{
    struct node* temp;
    while(Front != NULL)
    {
        temp = Front;
        Front = Front->next;
        free(temp);
    }
    Rear = NULL;
}


void printqueue(void)
{
    printf("current items in the queue is:\n");
    struct node* temp = Front;
    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("******************************************************\n\n");
}

struct node* Search(int x)
{
    struct node* newnode = Front;
    while((newnode != NULL)&&(newnode->data != x)) newnode = newnode->next;
    return newnode;
};
