#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

void insertintheBeggingftheList(int x)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=head;
    if(head != NULL)head->prev=newnode;
    head=newnode;
    if(newnode->next == NULL) tail = newnode;
    newnode->prev=NULL;
}

void insertintheEndoftheList(int x)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data =  x;
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        newnode->next = NULL;
        newnode->prev = NULL;
    }else
    {
        newnode->next = NULL;
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}

void insertwithLocation(int x, struct node* loc)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    if(loc->next != NULL){
            newnode->prev = loc;
            newnode->next= loc->next;
            loc->next = newnode;
            tail=newnode;

    }else
    {
        newnode->prev = loc;
        newnode->next= loc->next;
        loc->next = newnode;
        (newnode->next)->prev=newnode;
    }

}

void deletefromtheBeggingftheList(void)
{
    if(head == NULL) return;
    struct node* newnode;
    newnode = head;
    if(head == tail)
    {
        head = NULL;
        tail = NULL;
    }else{
        (newnode->next)->prev = NULL;
        head = newnode->next;
    }
    free(newnode);
}

void deletefromtheEndoftheList(void)
{
    if(head == NULL) return;
    struct node* newnode;
    newnode = tail;
    if(head == tail){
        head = NULL;
        tail = NULL;
    }else
    {
        (newnode->prev)->next = NULL;
        tail = tail->prev;
    }
    free(newnode);
}

void deletewithLocation(struct node* loc)
{
    if(loc->next == NULL) return;
    struct node* newnode;
    newnode = loc->next;
    loc->next = newnode->next;
    if(loc->next == NULL) tail = loc;
    else (loc->next)->prev = loc;
    free(newnode);
}

void deletelist(void)
{
    if(head == NULL) return;
    struct node* newnode;
    while(head != NULL){
        newnode = head;
        head = head->next;
        free(newnode);
    }
    tail = NULL;
}

void Print(void)
{
     printf("hello!\t");
     if(head == NULL){printf("list is empty");}else
        {
            struct node* prev = head;
            while(prev != NULL)
            {
                printf("%d\t", prev->data);
                prev=prev->next;
            }
            printf("\n");
        }
}
struct node* Search(int x)
{
    struct node* newnode = head;
    while((newnode != NULL)&&(newnode->data != x)) newnode = newnode->next;
    return newnode;
};

int main(void)
{
    insertintheBeggingftheList(15);
    insertintheEndoftheList(5);
    insertwithLocation(20, tail->prev);
    Print();
    return 0;
}
