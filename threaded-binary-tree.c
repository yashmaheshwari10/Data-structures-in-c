#include <stdio.h>
#include<stdlib.h>

struct node{
    struct node *left;
    struct node *right;
    int lbit;
    int rbit;
    int data;
};
struct node *root;

void start_tree(){
    root=NULL;
}

void insert(){
    int data;
    struct node *ptr;
    struct node *temp;
    ptr=(struct node *) malloc(sizeof (struct node));
    temp=(struct node *) malloc(sizeof (struct node));
    printf("enter data to be inserted");
    scanf("%d",&data);
    if(root==NULL){
        root=ptr;
        ptr->left=NULL;
        ptr->right=NULL;
        ptr->data=data;
        ptr->lbit=0;
        ptr->rbit=0;
        return;
    }
    else{
        ptr=root;
        int level;
        printf("enter level at which you want to insert data:");
        scanf("%d",&level);
        for(int i=1;i<level;i++){
            int node;
            printf("where do you wan to insert node?(l/r)");
            scanf("%d",&node);
            switch (node) {
                case 1:
                    if(ptr->left!=NULL)
                        ptr=ptr->left;
                    else
                        printf("invalid");
                    break;
                case 2:
                    if(ptr->right!=NULL)
                        ptr=ptr->right;
                    else
                        printf("invalid");
                    break;
                default:
                    printf("please enter valid response(l/r)");
                    i--;
                    break;
            }
        }
        //temp=ptr;
        printf("hi");
        int node;
        printf("where do you wan to insert node?(l/r)");
        scanf("%d",&node);
        switch (node) {
            case 1:
                if(ptr->lbit==0) {
                    ptr->lbit=1;
                    ptr->left=temp;
                    printf("hii");
                    temp->right=ptr;
                    temp->data = data;
                    printf("hiii");

                    temp->left=root;

                    temp->lbit=0;
                    temp->rbit=0;
                    //root=ptr;
                    return;
                }
                else
                    printf("invalid");
                break;
            case 2:
                if(ptr->rbit==0){
                    ptr->rbit=1;
                    ptr->right=temp;
                    printf("hii");
                    temp->left=ptr;
                    temp->data = data;
                    printf("hiii");

                    temp->right=root;

                    temp->lbit=0;
                    temp->rbit=0;
                    //root=ptr;
                    return;
                }

                else
                    printf("invalid");
                break;
            default:
                printf("please enter valid response(l/r)");
                break;
        }
    }

}

void display(){
    printf("hi");
    struct node *ptr;
    ptr=root;
    printf("%d",ptr->data);
    if(ptr->lbit==1){
        while(ptr->lbit!=0) {
            printf("hi");
            ptr = ptr->left;
            printf("%d", ptr->data);
        }

        printf("%d", ptr->data);

        ptr=ptr->right;
            printf("%d",ptr->data);

    }
    if(ptr->rbit==1){
        ptr=ptr->right;
        printf("%d",ptr->data);
        if(ptr->lbit==0){
            ptr=ptr->right;
            if(ptr!=root)
                printf("%d",ptr->data);
            else
                return;
        }
    }
    else{
        printf("scam");
        return;
    }
    return;
}

int main(){
      start_tree();
      int ch;
      while(1) {
          printf("enter choice:"
                 "1: insert"
                 "2: display inorder"
                 "3: quit");
          scanf("%d", &ch);
          switch (ch) {
              case 1:
                  insert();
                  break;
              case 2:
                  display();
                  break;
              case 3:
                  exit(0);

          }
      }
}
