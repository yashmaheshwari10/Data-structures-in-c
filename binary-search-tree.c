#include <stdio.h>
#include<stdlib.h>

struct node{
    struct node *left;
    struct node *right;
    int data;

};
struct node *root;


void create_list(){
    root=NULL;
}

//void insert_first(){
//   struct node *p=(struct node *)malloc (sizeof(struct node));
//   int data;
//    printf("enter data:");
//    scanf("%d",&data);
//   p->data=data;
//   root=p;
//   p->left=NULL;
//   p->right=NULL;
//
//}

struct node *newnode(int data){
    struct node *temp=(struct node *) malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    printf("%d",temp->data);

    return temp;
}
struct node *insert(struct node *temp,int data){

        if(temp==NULL){
//            newnode(temp,data);
            printf("hi");
            return newnode(data);
        }

        else if(data>temp->data){
            temp->right=insert(temp->right,data);
        }
        else{
            temp->left=insert(temp->left,data);

        }
    return temp;
}

void display_preorder(struct node *root){
    if(root!=NULL){
        printf("%d",root->data);
        display_preorder(root->left);
        display_preorder(root->right);
    }
}

void display_postorder(struct node *root){
    if(root!=NULL){
        printf("%d",root->data);
        display_postorder(root->right);
        display_postorder(root->left);
    }
}

void display_inorder(struct node *root){
    if(root!=NULL) {
        if (root->left != NULL) {
            printf("%d", root->left->data);
            display_inorder(root->left);
        }
        printf("%d",root->data);
        if(root->right!=NULL){
            printf("%d",root->right->data);
            display_inorder(root->right);
        }
    }
}

void search(int key){
    struct node *temp;
    temp=root;
    int i=0;
    while(temp!=NULL) {
        if (key == temp->data) {
            i = 1;
            break;
        } else if (key < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    if(i==1){
        printf("found");
    }
    else{
        printf("not found");
    }
}

void menu(int choice) {
int key;
int data;
    while (1) {
        switch (choice) {
            case 1:
                printf("enter data");
                scanf("%d", &data);
                root = insert(root, data);

                return;

                case 2:
                printf("enter data");
                scanf("%d", &data);
                insert(root, data);
                return;
            case 3:
                display_preorder(root);
                return;
            case 4:
                display_postorder(root);
                return;
            case 5:
                display_inorder(root);
                return;


            case 6:
                printf("enter key");
                scanf("%d",&key);
                search(key);
                return;

            case 7:
                exit(0);
                        }
    }

}

int main() {
    while(1) {
        printf("1=insert first\n");
        printf("2=insert\n");
        printf("3=display preorder\n");
        printf("4=display postorder\n");
        printf("5=display inorder\n");

        printf("6=search\n");
        printf("7=exit\n");

        int choice;

        printf("enter choice");
        scanf("%d", &choice);
//    int data;
        menu(choice);
    }
}



