#include <stdio.h>
int arr[10];
#define MAX 10
int top=-1;

void push(){
   if(top==MAX){
        printf("stack is full!");
        return;
   }
   else{
       int data;
       printf("enter element:");
       scanf("%d",&data);
       top++;
       arr[top]=data;
   }
}


int pop(){
    if(top==-1){
        printf("stack is empty");
    }
    else{
        return arr[--top];
    }
}


void display(){
    if(top==-1){
        printf("stack is empty");
        return;
    }
    for(int i =0;i<=top;i++){
        printf("\n%d \n",arr[i]);
    }
}


int main() {
    int n;

    while (1){
        printf("what would you like to do(1 for push,2 pop,3 display)");
        scanf("%d",&n);
    switch (n) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
    }
    }

}
