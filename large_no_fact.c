#include<stdio.h>
#include<stdlib.h>

//creating a node
typedef struct node{
    short int value;
    struct node* next;
    struct node* prev;
}node;

//function to push the element in the linked list
void insert_begin(node** head, node** tail, short int value)
{
    //creating a node to store the value
    node* temp= (node*)malloc(sizeof(node));

    //intializing the values of the temp node
    temp->value= value;
    temp->next= NULL;
    temp->prev= NULL;

    //if the linked list is empty
    if(*head==NULL)
    {
        *head= temp;
        *tail= temp;
    }
    else{
        (*head)->prev= temp;
        temp->next= *head;
        *head= temp;
    }
}

//function to print the linked list
void print_ll(node** head)
{
    //temporary node variable
    node* temp;
    temp= *head;
    while(temp!=NULL)
    {
        printf("%hd",temp->value);
        temp=temp->next;
    }
    printf("\n");
}

//defining the function multiply
void multiply(node** head, node** tail, int i)
{
    node* temp= *tail;
    int carry=0, x=0, y=0;

    while(temp!=NULL)
    {
        x= (temp->value)*i+carry;
        y= x%10;
        temp->value= y;
        carry= x/10;
        temp= temp->prev;
    }
    while(carry!=0){
        insert_begin(head, tail, carry%10);
        carry/=10;
    }
}
int main(void)
{
    //creating a pointer variable of type node
    node* head= NULL;
    node* tail= NULL;

    //input a number
    int number=0;
    printf("Finding factorial of a number\nEnter a number: ");
    scanf("%d",&number);

    //push the value of factorial 0 initially in the linked list
    insert_begin(&head, &tail, 1);

    for(int i=2; i<=number; i++)
    {
        multiply(&head, &tail, i);
    }
    //print the value of the factorial
    print_ll(&head);

    //free the head pointer
    free(head);
    //free the tail pointer
    free(tail);
}