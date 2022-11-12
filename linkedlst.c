#include<stdio.h>
#include<stdlib.h>

/* struct node to create a linked list node */
struct node{
    int data;
    struct node *next;
} ;
struct node *head=NULL; /* pointer to initial node */
struct node *current=NULL; /* used for pointing nodes, helpful in display and other operations */
/* create() function to create initial node */ 
void create(){
    if(head==NULL){
        struct node *ptr;
        int temp;
        ptr=(struct node *)malloc(sizeof(struct node));
        head=ptr;
        printf("Enter initial element\t");
        scanf("%d",&temp);
        ptr->data=temp;
    }
    else{
        printf("\nList already created try insert()/ Delete all and begin\n");
    }
}
/* insert() function to insert further nodes */

void insert(){
    if(head==NULL){
        printf("\nTry create() function, List is not created\n");
    }
    else{
        current=NULL;
        current=head;
        if(head->next!=NULL){
            while(current->next!=NULL){
                current=current->next;
            }
        }
        struct node *ptr1;
        int temp1;
        ptr1=(struct node *)malloc(sizeof(struct node));
        printf("Enter data\t");
        scanf("%d",&temp1);
        ptr1->data=temp1;
        current->next=ptr1;
    }
    
}
/* del() to delete a node, from beginning or at specific site or at the end */ 

void del(){
    int option,c;
    current=NULL;
    if(head==NULL){
        printf("\nList empty....Sorry no deletion possible\n");
    }
    else if(head->next==NULL){
        head=NULL;
    }
    else{
        display();
        printf("\nSelect the site you want to delete\n1.At Beginning\n2.Specific element\n3.At End\n");
        scanf("%d",&option);
        if(option==1){
            head=head->next;
        }
        else if(option==2){
            int del_ele;
            printf("Enter Element:\t");
            scanf("%d",&del_ele);
            struct node *prev;
            current=head;
            while(current->data!=del_ele){
                prev=current;
                current=current->next;
            }
            prev->next=current->next;
            current=NULL;
        }
        else if(option==3){
            struct node *prev;
            current=head;
            while(current->next!=NULL){
                prev=current;
                current=current->next;
            }
            prev->next=NULL;
            current=NULL;
        }
        else{
            printf("Enter correct option\n");
            del();
        }
    }
}

/* display() function to display list */
void display(){
    if(head==NULL){
        printf("Linked List empty\n");
    }
    else{
        struct node *disp;
        disp=head;
        printf("%d->",disp->data);
        while(disp->next!=NULL){
            disp=disp->next;
            printf("%d->",disp->data);
        }
        printf("NULL\n");
    }
}

/* length() function to find length of the list */
void length(){
    current=NULL;
    int len=0;
    if(head==NULL){
        printf("Length of the list = 0\n");
    }
    else if(head->next==NULL){
        printf("Length of the list = 1\n");
    }
    else{
        current=head;
        len++;
        while(current->next!=NULL){
            current=current->next;
            len++;
        }
        printf("Length of the list = %d\n",len);
    }
}

int main(){
    printf("-------Interactive Linked List Operations Implementation--------\n");
    int option_sel;
/* Iteratively seek user input to perform operation*/    
    while(1){
        printf("Enter Option\n1.Create\n2.Insert\n3.Delete\n4.Length\n5.Display\n6.Exit\n");
        scanf("%d",&option_sel);
        if(option_sel==1){
            create();
        }
        else if(option_sel==2){
            insert();
        }
        else if(option_sel==3){
            del();
        }
        else if(option_sel==4){
            length();
        }
        else if(option_sel==5){
            display();
        }
        else if(option_sel==6){
            printf("----ThankYou--------\n------END------\n");
            break;
        }
        else{
            printf("Enter correct option\n");
        }
    }
    
}