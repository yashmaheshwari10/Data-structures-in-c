#include <stdio.h>


int arr[10];
#define SIZE 10
int front=-1;
int rear=-1;


void enqueue(){
    int data;
    printf("enter data:");
    scanf("%d",&data);
    if(rear==SIZE){
        printf("queue full!!!!");
        return;
    }
    else if(front==-1){
        front++;
        rear++;
        arr[rear]=data;

    }
    else{
        rear++;
        arr[rear]=data;

    }
}


void dequeue(){
    if(rear==-1){
        printf("element to daal bhadve!");
        return;
    }
    else if(rear==front){
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
}


void display(){
    for(int i=front;i<=rear;i++){
        printf("%d",arr[i]);
    }
};
int main() {

    while (1) {
        printf("what to do today(1 for enqueue 2 for dequeue 3 for display):");
        int n;
        scanf("%d", &n);
        switch (n) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    }
}