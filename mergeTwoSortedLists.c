// In this program we are going to merger K sorted Lists into one single list.
#include <stdio.h>
#include <stdlib.h>

// structure of the node.
struct node{
    int data;
    struct node *next;
};

// This function  creates new node and return address of the newely created node.
struct node* newNode(int data){
    struct node *newnode  = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
};

// This function merger two lists into one single list and returns head of the final merged list.
struct node* mergeList(struct node *head1, struct node *head2){
    // If head of one list is null then just return head of another list.
    // head will point to the first node of merged list. Temp will point to the last node in merged sorted list.
    struct node *head , *temp;
    if(!head1 || !head2){
        return (!head1)?head2:head1;
    }
    // Initializing head with the node with least value among two lists.
    if(head1->data <= head2->data){
        head = head1;
        head1 = head1->next;
    }
    else{
        head = head2;
        head2 = head2->next;
    }
    // Initializig temp with the first node.
    temp = head;
    while(head1 && head2){
        if(head1->data<=head2->data){
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }
    }
    if(!head1){
        temp->next = head2;
    }
    else{
        temp->next = head1;
    }

    return head;
}

void printList(struct node *head){
    //printf("Inside");
    struct node *temp = head;
    //printf("%p",temp);
    while(temp){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node *list1,*list2,*head;
    list1 = newNode(1);
    list1->next = newNode(3);
    list1->next->next = newNode(5);
    list1->next->next->next = newNode(10);
    list2 = newNode(2);
    list2->next = newNode(4);
    list2->next->next = newNode(7);
    //list2->next->next->next = newNode(8);
    //printList(list1);
    //printList(list2);

    head = mergeList(list1, list2);
    printList(head);
}