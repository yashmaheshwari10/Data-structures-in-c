#include<stdio.h>
#include<stdlib.h>



struct vertices{
    struct vertices *next;
    int vertex;
};
void create_graph();
void display();
void add();
void bfs();
void dfs();
void create_graph_adjmatrix();

struct vertices *adjlist[10];
int n;
int main(){
//    create_graph();
//
//dfs();
//bfs();
//create_graph_adjmatrix();
    printf("what would you like to do?");
    printf("\n1-create graph adjacency list\n2-create graph adjacency matrix\n3-bfs\n4-dfs ");
    int ch;
    scanf("%d",&ch);
    switch (ch) {
        case 1:
            create_graph();
            break;
        case 2:
            create_graph_adjmatrix();
            break;
        case 3:
            bfs();
            break;
        case 4:
            dfs();
            break;
    }

}

void create_graph() {
    struct vertices *p, *q;
    p = (struct vertices *) malloc(sizeof(struct vertices));
    q = (struct vertices *) malloc(sizeof(struct vertices));
    int vert;
    printf("enter number of vertices you want");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        adjlist[i] = (struct vertices *) malloc(sizeof(struct vertices));
        adjlist[i]->vertex = i + 1;
        adjlist[i]->next = NULL;
    }
    int counter = 0;
    for (int i = 1; i <= n; i++) {

     int j;
       printf("\nhow many vertices is %d adjacent to?", i);
       scanf("%d", &j);
        for (int k = 1; k <= j; k++) {
           add(counter,i);
       }
       counter++;
        }
        return;
    }


void display(){
    struct vertices *p;

    for(int i=0;i<n;i++){
        p=adjlist[i];
        while(p!=NULL){
            printf("%d\n",p->vertex);
            p=p->next;
        }
    }
}
void add(int counter,int i){
    struct vertices *p,*q;
    int vert;
    p=(struct vertices *) malloc(sizeof(struct vertices) );
    q=(struct vertices *) malloc(sizeof(struct vertices) );
    printf("\nwhich vertice is %d adjacent to?",i);
            scanf("%d",&vert);
            if(vert>n){
                printf("not a vertex!");
                return;
            }
            else {
                q = adjlist[counter];
                while (q->next != NULL) {
                    q = q->next;
                }
                q->next = p;


                p->vertex = vert;

                p->next = NULL;
            }
}

void dfs() {
    struct vertices *p;
    int stack[10];
    int top = 0;
    int visited[10];
    int count=0;
    int start=0;

    for(int i=0;i<n;i++) {
        p=adjlist[i];
//        visited[i]=p->vertex;
//        count++;
        while (p != NULL) {
            int flag=0;
            for(int i=0;i<=count;i++){

                if(p->vertex==visited[i]){
                    flag=1;
                }
            }
            if(flag!=1){
                stack[top] = p->vertex;
                visited[count]=p->vertex;
                p = p->next;
                top++;
                count++;
            }
            else{
                p=p->next;
            }
        }
    }
    top--;
    while(top>=0){

        printf("\n%d",stack[top]);
        top--;
    }


}

void bfs(){
    printf("\nbfs\n");
    struct vertices *p;
    int queue[10];
    int top = 0;
    int visited[10];
    int count=0;
    int start=0;



//    visited[0] = adjlist[0]->vertex;
//
//    count=0;
//    p = adjlist[0];
//    top++;
    for(int i=0;i<n;i++) {
        p=adjlist[i];
//        visited[i]=p->vertex;
//        count++;
        while (p != NULL) {
            int flag=0;
            for(int i=0;i<=count;i++){

                if(p->vertex==visited[i]){
                    flag=1;
                }
            }
            if(flag!=1){
                queue[top] = p->vertex;
                visited[count]=p->vertex;
                p = p->next;
                top++;
                count++;
            }
            else{
                p=p->next;
            }
        }
    }
    top--;
    while(start!=top){

        printf("\n%d",queue[start]);
        start++;
    }


}

void create_graph_adjmatrix(){
    int m;
    printf("how many vertices does graph has?");
    scanf("%d",&m);
    int adjmatrix[m][m];
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            adjmatrix[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++){
        printf("how many vertices is %d adjacent",i+1);
        int num;
        scanf("%d",&num);
        for (int j = 0; j < num; j++) {
            printf("which vertex is %d adjacent",i+1);
            int vert;
            scanf("%d",&vert);
            adjmatrix[i][vert-1]=1;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {

            // Print the value at Adj[i][j]
            printf("%d ", adjmatrix[i][j]);
        }
        printf("\n");
    }
}
