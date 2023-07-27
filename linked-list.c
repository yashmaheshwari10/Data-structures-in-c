#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;

void create_list(){
    head = NULL;
}
 void ins_first(){
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof (struct node));
    int val;

    printf("enter data:");
    scanf("%d",&val);
    ptr->data=val;
    ptr->next=head;
    head=ptr;
}
void ins_end(){
    struct node *ptr,*temp;
    ptr=(struct node *)malloc(sizeof (struct node));
    int val;

    printf("enter data:");
    scanf("%d",&val);
    ptr->data=val;
    if(head==NULL){
        ptr->next=NULL;
        head=ptr;
    }
    else{
        temp=head;
        while(temp ->next != NULL){
            temp = temp -> next;
        }
        temp->next=ptr;
        ptr->next=NULL;

    }
 }
 void ran_enter(){
     struct node *ptr,*temp;
     int loc,val;

     ptr=(struct node *)malloc(sizeof (struct node));


     printf("enter loc:");
     scanf("%d",&loc);
     printf("enter data:");
     scanf("%d",&val);
     ptr->data=val;

     temp=head;
     for(int i=0;i<loc-1;i++){
         temp=temp->next;
         if(temp==NULL){
             printf("sahi sahi khel lavde\n");
             return;
         }
     }

     ptr->next=temp->next;
     temp->next=ptr;

 }

 void display(){
     struct node *ptr;
     ptr = head;
     while(ptr != NULL){
         printf("%d ",ptr->data);
         ptr = ptr->next;
     }
 }

void delete_beg(){
    struct node *ptr;

    ptr=head;
    head=ptr->next;
    free(ptr);
}

void del_end(){
    struct node *ptr,*ptr1;
    ptr = head;
    if(head->next==NULL){
        head=NULL;
        free(head);
    }
    else{
        while(ptr->next!=NULL){
            ptr1=ptr;
            ptr=ptr->next;
        }
        ptr1->next=NULL;
        free(ptr);

    }
}

void ran_delete(){
    struct node *ptr,*ptr1;
    ptr=head;
    int loc;
    printf("enter loc to del:");
    scanf("%d",&loc);
    for(int i=0;i<loc;i++){
        ptr1=ptr;
        ptr=ptr->next;
    }

    ptr1->next=ptr->next;
    free(ptr);

}
 int main(){
    create_list();
     ins_first();
     ran_enter();
     ran_enter();
     ins_end();
     display();
     printf("\n");
     delete_beg();
     display();
     del_end();
     printf("\n");
     display();
     ran_delete();
     printf("\n");
     display();
 }