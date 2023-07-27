#include <stdio.h>
#include<stdlib.h>
struct node{
    struct node *next;
    int data;
};
struct node *head=NULL;
int top=5;

void push1(){
    struct node *ptr;
    int data;

    ptr=(struct node *)malloc(sizeof (struct node));
    printf("enter data");
    scanf("%d",&data);
    ptr->data=data;
    ptr->next=head;
    head=ptr;


}
void push(int cur){

        struct node *ptr, *temp;
        int data;

        ptr = (struct node *) malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d", &data);
        ptr->data = data;
        temp = head;

        for (int i = 0; i < cur; i++) {
            temp = temp->next;
        }
        if (cur == top) {
            ptr->next = NULL;
            temp->next = ptr;
        } else {
            ptr->next = temp->next;
            temp->next = ptr;
        }


}

void pop()
{
    struct node *temp;
    struct node *ptr;
    temp=head;
    while(temp->next->next!=NULL){
//        printf("%d",temp->data);
        temp=temp->next;
    }
    ptr=temp->next;
    temp->next=ptr->next;
    free(ptr);

}
void display(){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
}
int main() {
    push1();
    int n = 0;
//    push1();
//    push(1);
    while (1) {
        for (int n; n <= top; n++) {
            push(n);
        }
        printf("ov");
        break;
    }
    pop();
    display();
}