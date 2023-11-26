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

void enqueue(int data){
     struct node* new_node=create_node(data);
     
     if (head==NULL) {
        head =new_node ;
        return;
     }
    struct node* p=head;
     while(p->next!=NULL){
        p=p->next;
     }
     p->next=new_node;
}

int dequeue(){
    struct node* p=head;
    if (head == NULL) {
        printf("Queue is empty");
        exit(0);
    }

    head=head->next;
    int x=p->data;
    free(p);
    return x;
}

void display(){
    if (head == NULL) {
        printf("Queue is empty");
        exit(0);
    }
    struct node *p = head;
    while(p != NULL) {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    int op;
      char cont='y';
      printf("Enter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display\n");
        
      do{
            int new_data;
            printf("enter your option: ");
            scanf("%d",&op);
            switch (op)
            {
            case 1:
                  printf("Enter the data : ");
                  scanf("%d",&new_data);
                  enqueue(new_data);
                  printf("successfull\n");
                  break;

            case 2:
                  new_data=dequeue();
                  printf("The deleted data is %d\n",new_data);
                  break;

            case 3:
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