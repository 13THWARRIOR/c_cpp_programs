#include <stdio.h>
#include <stdlib.h>

int count = 0, mid = 0, n;

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
}NODE;

NODE *head, *temp, *last;

struct node* createNode() {
    NODE *new = NULL;
    new = malloc(sizeof(NODE));
    if (new == NULL) {
        printf("Memory not allocated.\n");
        return NULL;
    }
    count++;
    printf("number of nodes : %d\n",count);
    if(count > 1) {
        mid = count/2;
        printf("mid is : %d\n",mid);
    }
    return new;
}

void printData() {
    if(head!=NULL) {
        NODE *front = head;
        int a = 1;
        while(a) {
            printf("data is : %d\n",front->data);
            printf("preset node address : %d\n",front);
            printf("present node next : %d\n",front->next);
            printf("present node prev : %d\n",front->prev);
            front = front->next;
            if (front==NULL) {
                break;
            } else if (front == head) {
                a=0;
            } else {
                continue;
            }
        }
    } else {
        printf("linklist empty nothing to show\n");
    }
}

void addNode(int data) {
    if (head==NULL) {
        printf("head is null. creating a head with data : %d\n",data);
        head = createNode();
        if (head!=NULL) {
            head->data = data;
            head->next = NULL;
            head->prev = NULL;
            last = head;
        } else {
            printf("no memory allocated for head\n");
            return;
        }
    } else {
        printf("Creating a new node with data : %d\n",data);
        temp = createNode();
        if (temp!=NULL) {
            temp->data = data;
            last->next = temp;
            head->prev = temp;
            temp->prev = last;
            temp->next = head;
            last = temp;
            temp = NULL;
        } else {
            printf("memory was not allocated for a next node");
            return;
        }
    }
}

int main() {
    int data,a=0;
    printf("Please choose options below:\n");
    while(1) {
        printf("choose :\n1. for adding a node press 1\n2. printing data press 2\n");
        scanf("%d",&n);
        switch(n) {
            case 1: printf("\nPlease enter data in integer format:\n");
                    scanf("%d",&data);
                    addNode(data);
                    break;
            case 2: printf("printing data\n");
                    printData();
                    break;
            default: a=1;
                     break;
        }
        if (a) {
            break;
        }
    }
    return 0;
}