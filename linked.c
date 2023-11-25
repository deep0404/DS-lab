#include <stdio.h>
#include <stdlib.h>

struct node{
      int data;
      struct node* next;
};

struct node* head=NULL;

struct node* create_node(int data){
      struct node* new_node= (struct node*)malloc(sizeof(struct node));
      new_node->data=data;
      new_node->next=NULL;
      return new_node;
}

void insert_at_beginning(int new_data){
      struct node* new= (struct node*) malloc (sizeof(struct node*));
      new->data=new_data;
      new->next=head;
      head=new;
}

void insert_at_end(struct node* p,int new_data){
      struct node* new= create_node(new_data);

      
      if(p==NULL){
            head=new;
            return;
      }

      while(p->next!=NULL){
            p=p->next;
      }

      p->next=new;

}

void insert_at_pos(struct node* p,int new_data,int pos){
      for(int i=0;i<pos-1;i++)
            p=p->next;

      struct node* new_node=create_node(new_data);
      new_node->next=p->next;
      p->next=new_node;
            
}

void display(struct node*p){
      while(p!=NULL){
            printf("%d ",p->data);
            p=p->next;
      }
}

int delete_at_begin(){
      struct node* p=head;
      head=head->next;
      int deleted_data=p->data;
      free(p);
      return deleted_data;
}

int delete_at_end(){
      struct node* p=head;
      struct node* q;
      if(head==NULL){
            printf("List empty");
            return -1;
      }

      while(p->next!=NULL){
            q=p;
            p=p->next;
      }
      q->next=NULL;
      
      int deleted_data=p->data;
      free(p);
      return deleted_data;
}

int delete_at_pos(int pos){
      struct node* p=head;
      struct node* q;

      for(int i=0;i<pos;i++){
            q=p;
            p=p->next;
      }

      q->next=p->next;
      int deleted_data=p->data;
      free(p);
      return deleted_data;

}

void main(){
      int op;
      char cont='y';
      int pos;
      printf("Enter 1 for insertion at beginning\nEnter 2 for insertion at end\nEnter 3 for insertion at any position\nEnter 4 to display\n");
      printf("Enter 5 to delete from front\nEnter 6 to delete at end\nEnter 7 to delete at pos\n");

      do{
            int new_data;
            printf("enter your option: ");
            scanf("%d",&op);
            switch (op)
            {
            case 1:
                  printf("Enter the data of the node: ");
                  scanf("%d",&new_data);
                  insert_at_beginning(new_data);
                  break;

            case 2:
                  printf("Enter the data of the node: ");
                  scanf("%d",&new_data);
                  insert_at_end(head,new_data);
                  printf("Successfull\n");
                  break;

            case 3:
                  
                  printf("Enter the data of the node: ");
                  scanf("%d",&new_data);
                  printf("Enter the position of the node: ");
                  scanf("%d",&pos);
                  insert_at_pos(head,new_data,pos);
                  break;
            case 4:
                  display(head);
                  break;

            case 5:
                  new_data=delete_at_begin();
                  printf("The deleted data is %d",new_data);
                  break;

            case 6:
                  new_data=delete_at_end();
                  printf("The deleted data is %d",new_data);
                  break;

            case 7:
                  printf("Enter the position of the node: ");
                  scanf("%d",&pos);
                  new_data=delete_at_pos(pos);
                  printf("The deleted data is %d",new_data);
                  break;
            default:
                  printf("Invalid option");
                  break;
            }
            printf("do you want to continue--y/n");
            scanf("%s",&cont);
      }while(cont=='y');
}