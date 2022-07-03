#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

typedef struct Node node;

node *CreateNode(int);
node *CreateList(int);
void display();
void insert_beg();
void insert_end();
void insert_mid(int);
void delete(int);

int n;
node *head;

void main()
{
    int choice1, choice2, pos;
    
    while(1)
    {
        printf("\n***Linked List MENU ***\n");
        printf("\n1.Create\n2.Display\n3.Insert\n4.Delete\n5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice1);

        switch(choice1)
        {
            case 1:
                    printf("\n**Creation***\n");
                    printf("Enter the number of nodes the Linked list have: ");
                    scanf("%d", &n);
                    head = CreateList(n);
                    break;
            case 2:
                    printf("\n***Display***\n");
                    display();
                    break;
            case 3:
                    printf("\n***Insertion***\n");
                    printf("\nInsertion at:\n1.At the beginning\n2.At the end\n3.At a position\n");
                    printf("Enter the choice: ");
                    scanf("%d", &choice2);
                    switch(choice2)
                    {
                        case 1:
                                printf("\nInsertion at the begining***\n");
                                insert_beg();
                                break;
                        case 2:
                                printf("\n***Insertion at the end***\n");
                                insert_end();
                                break;
                        case 3:
                                printf("\n***Insertion at the position***\n");
                                printf("Enter the position of the node to be inserted: ");
                                scanf("%d", &pos);
                                insert_mid(pos);
                                break;
                        default:
                                printf("Invalid choice....");
                    }
                    break;
            case 4:
                    printf("\n***Deletion***\n");
                    printf("Enter the position of the node to be deleted: ");
                    scanf("%d", &pos);
                    delete(pos);
                    break;
            case 5:
                    exit(0);
            default:
                    printf("\nInvalid Choice...");
        }
    }
}

node *CreateNode(int i)
{
    node *newnode;
    newnode = (node *) malloc (sizeof(node));
    printf("Enter the data of Node-%d: ", i);
    scanf("%d", &newnode -> data);
    newnode -> next = NULL;
    return newnode;
}

node *CreateList(int n)
{
    node *newnode, *temp, *head;
    for(int i = 1; i <= n; i++)
    {
        newnode = CreateNode(i);
        if(head == NULL)
            head = newnode;
        else
        {
            temp = head;
            while(temp -> next != NULL)
                temp = temp -> next;
            temp -> next = newnode;
        }
    }
    return head;
}

void display()
{
    node *temp = head;
    printf("The linked list: ");
    while(temp != NULL)
    {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL");
}


void insert_beg()
{
    node *newnode;
    newnode = CreateNode(1);
    newnode -> next = head;
    head = newnode;
    n += 1;
}

void insert_end()
{
    node *newnode, *temp;
    newnode = CreateNode(1);
    temp = head;
    while(temp -> next != NULL)
    temp = temp -> next;
    temp -> next = newnode;
    n += 1;
}


void insert_mid(int i)
{
    node *newnode, *temp;
    int count = 2;
    newnode = CreateNode(1);
    temp = head;
    if(i == 1)
        printf("Here you cannot insert at beginning");
    if((i <= n) == 0 )
        printf("Cannot be inserted at the position %d.", i);
    
    while(count++ < i)
        temp = temp -> next;
    newnode -> next = temp -> next;
    temp -> next = newnode;
    n =+ 1;


    
}

void delete(int i)
{
    node *temp, *prev;
    int count;
    prev = temp = head;
    for(count = 2; count < i; count++)
    {
        prev = prev -> next;
        temp = prev -> next;
    }
    if(i == 1)
        head = head -> next;
    else
    prev -> next = temp -> next;
    free(temp);
    n -= 1;
}