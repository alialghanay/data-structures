#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insertintheEndoftheList(int x)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
    }else
        {
            struct node* prev = head;
            while(prev->next != NULL)
                prev=prev->next;
            prev->next = newnode;

        }

}

void insertintheBeggingftheList(int x)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=head;
    head=newnode;
}


void insertwithLocation(int x, struct node* loc)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    if(loc->next == NULL) return;
    newnode->next=loc->next;
    loc->next=newnode;
}


void deletefromtheBeggingftheList(void)
{
    struct node* newnode;
    if(head == NULL) return;
    newnode = head;
    head = newnode->next;
    free(newnode);
}

void deletefromtheEndoftheList(void)
{
    struct node* newnode;
    if(head == NULL) {return;}else if(head->next == NULL){
        newnode = head;
        head = NULL;
        free(newnode);
    }else
    {
        struct node* prev = head;
        newnode = head->next;
        while(newnode->next != NULL)
        {
            prev = newnode;
            newnode = newnode->next;
        }
            prev->next = NULL;
            free(newnode);
    }
}

void deletewithLocation(struct node* loc)
{
    struct node* newnode = loc->next;
    if(loc->next == NULL) return;
    loc->next = newnode->next;
    free(newnode);

}

void deletelist()
{
    struct node* newnode;
    while(head != NULL){
        newnode = head;
        head=head->next;
        free(newnode);
    }
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
struct node* Search(int data)
{
    if(head == NULL) return;
    struct node* newnode = head;
    while((newnode != NULL)&&(newnode->data != data)) newnode = newnode->next;
    return newnode;
}
int main(void)
{
    insertintheEndoftheList(15);
    insertintheEndoftheList(150);
    insertintheEndoftheList(1500);
    insertintheEndoftheList(15000);
    insertintheBeggingftheList(47);
    deletefromtheBeggingftheList();
    insertintheEndoftheList(470);
    deletefromtheEndoftheList();
    insertwithLocation(20, Search(150));
    deletewithLocation(Search(1500));
    Print();
    deletelist();
    Print();
    return 0;
}
