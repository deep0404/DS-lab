#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;
struct node* create_node(int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

void push(int data){
    struct node* new_node=create_node(data);


    if(head==NULL){
        head=new_node;
        return;
    }

    struct node* p=head;
    while(p->next!=NULL)
        p=p->next;

    p->next=new_node;
}

int pop(){
    struct node* p=head;
    struct node* q;

    if(p==NULL){
        printf("Stack is empty\n");
    }

    while(p->next!=NULL){
        q=p;
        p=p->next;
    }

    int x=p->data;
    q->next=NULL;
    free(p);
    return x;
}

int peek(){
    if(head==NULL){
        printf("Stack is empty\n");
    }
    struct node* p=head;
    while(p->next!=NULL)
        p=p->next;
    
    int x=p->data; 
    return x;
}

void display(){
    struct node* p=head;
    while(p!=NULL){
        printf("%d  ",p->data);
        p=p->next;
    }
    printf("\n");
}

void main(){
    int op;
      char cont='y';
      printf("Enter 1 for push\nEnter 2 for pop\nEnter 3 for peek\nEnter 4 to display\n");
        
      do{
            int new_data;
            printf("enter your option: ");
            scanf("%d",&op);
            switch (op)
            {
            case 1:
                  printf("Enter the data : ");
                  scanf("%d",&new_data);
                  push(new_data);
                  printf("successfull\n");
                  break;

            case 2:
                  new_data=pop();
                  printf("The deleted data is %d\n",new_data);
                  break;

            case 3:
                  new_data=peek();
                  printf("The peek element is %d\n",new_data);
                  break;
            case 4:
                  display(head);
                  break;

            
            default:
                  printf("Invalid option\n");
                  break;
            }
            printf("do you want to continue(y/n)--");
            scanf("%s",&cont);
      }while(cont=='y');
}

