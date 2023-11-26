#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head=NULL;

struct node* create_node(int data){
    struct node* new_node= (struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    new_node->prev=NULL;
}

void insert_at_begin(int data){
    struct node* new_node=create_node(data);
    if(head==NULL) {
        head =new_node ;
    }
    else {
        head->prev=new_node;
        new_node->next=head;
        head=new_node;
    }

}

void insert_at_end(int data){
    struct node* new_node=create_node(data);
    struct node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=new_node;
    new_node->prev=p;
}

void insert_at_pos(int data,int pos){
    struct node *new_node=create_node(data);
    struct node *p= head;

    if(pos>sizeof(struct node*)){
        printf("Insertion not possible\n");
        return;
    }

    for(int i=0;i<pos-1;i++){
        p=p->next;
    }
    new_node->next=p->next;
    p->next->prev=new_node;
    p->next=new_node;
    new_node->prev=p;
}

int delete_from_begin(){
    struct node* p=head;
    if(head == NULL){
        printf("Empty");
    }
    else{
        head=head->next;
        head->prev=NULL;
        int x=p->data;
        free(p);
        return x;
    }

}

int delete_at_end(){
    struct node* p=head;
    if(head == NULL){
        printf("Empty");
    }

    else{
        while(p->next!=NULL){
        p=p->next;
    }
    p->prev->next=NULL;
    int x=p->data;
    free(p);
    return x;
    }
}

int delete_at_pos(int pos){
    struct node *p = head;
    for(int i=0;i<pos;i++){
        p=p->next;
    }
    p->prev->next=p->next;
    p->next->prev=p->prev;
    int x=p->data;
    free(p);
    return x;
}

void display(){
    struct node *p=head;
    while(p!=NULL){
        printf("%d  ",p->data);
        p=p->next;
    }
    printf("\n");
}

void main(){
      int op;
      char cont='y';
      int pos;
      printf("Enter 1 for insertion at beginning\nEnter 2 for insertion at end\nEnter 3 for display\nEnter 4 to insert at any position\n");
      printf("Enter 5 to delete from beginning\nEnter 6 to delete from end\nEnter 7 to delete from pos\n");

      do{
            int new_data;
            printf("enter your option: ");
            scanf("%d",&op);
            switch (op)
            {
            case 1:
                  printf("Enter the data of the node: ");
                  scanf("%d",&new_data);
                  insert_at_begin(new_data);
                  break;

            case 2:
                  printf("Enter the data of the node: ");
                  scanf("%d",&new_data);
                  insert_at_end(new_data);
                  printf("Successfull\n");
                  break;

            case 3:
                  display();
                  break;

            case 4:
                  printf("Enter the data of the node: ");
                  scanf("%d",&new_data);
                  printf("Enter the position of the node: ");
                  scanf("%d",&pos);
                  insert_at_pos(new_data,pos);
                  break;

            case 5:
                  new_data=delete_from_begin();
                  printf("The deleted data is %d\n",new_data);
                  break;

            case 6:
                 new_data=delete_at_end();
                  printf("The deleted data is %d\n",new_data);
                  break;

            case 7:
                printf("Enter the position of the node: ");
                  scanf("%d",&pos);
                  new_data=delete_at_pos(pos);
                  printf("The deleted data is %d\n",new_data);
                  break;

            default:
                  printf("Invalid option");
                  break;
            }
            printf("do you want to continue(y/n)--");
            scanf("%s",&cont);
      }while(cont=='y');
}
