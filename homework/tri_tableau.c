/*
@Author Seifeddine Sghaier
Date 20/04/2014

Tri D'un tableau en C en utilisant 4 methode de Tri.
Tri à bulles,Tri par selection,Tri par insertion,Tri par segmentation(Tri rapide) 
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void alea(int **Tab,int n){
    int i;
    srand(time(NULL));
    for(i = 0;i<n;i++){
            Tab[i] = rand() % 100 ;
    }
    print_tab(Tab,n);

}

void init(int *n){
    system("cls");
    printf("\n\t/** Le tri d'un tableau en utilisant plusieurs methodes **/\n\n");
    printf("Entrer n le nombre d'element dans le tableau:\n");
    int t;
    scanf("%d",&t);
    *n = t;
}
void remp(int **Tab,int n){
    char  c;
    printf("Remplie le tableau aleatoirement(O/N)?\n");
    scanf(" %c",&c);
    c = toupper(c);
    if(c == 'O'){
        alea(Tab,n);
    }
    else if(c == 'N'){
        int i = 0;
        while(i<n){
            printf("Entrer Tab[%d]: ",i+1);
            int t;
            scanf("%d",&t);
            Tab[i] = t;
            i++;
        }
    }else{
        printf("Reponse Invalide!!\n");
        remp(Tab,n);
    }

}

void print_tab(int **Tab,int n){
    int i;
    for(i =0; i<n;i++){
        printf("%d\t",Tab[i]);
    }
    printf("\n");
}

void selection(int **Tab,int n){
    int i,j;
    for(i = 0; i<n-1; i++){
        int m =i;
        for(j = i+1;j<n;j++)
            if(Tab[j]<Tab[m])
                m = j;
        int tmp = Tab[m];
        Tab[m] = Tab[i];
        Tab[i] = tmp;
    }
}
void insertion(int **Tab,int n){
   int i, j;
   for (i = 0; i < n; ++i) {
       int tmp = Tab[i];
       for (j = i; j > 0 && Tab[j-1] > tmp; j--)
           Tab[j] = Tab[j-1];
       Tab[j] = tmp;
   }
}
void bulles(int **Tab,int n){
    int i;int tmp;
    int b = 1;
    while(b){
        b = 0;
        for(i = 0; i<n; i++){
            if(Tab[i]>Tab[i+1]){
                tmp = Tab[i] ;
                Tab[i] = Tab[i+1];
                Tab[i+1] = tmp;
                b=1;
            }
        }
    }
}
int part(int *Tab, int p, int r) {
    int pivot = Tab[p], i = p-1, j = r+1;
    int temp;
    while (1) {
        do
            j--;
        while (Tab[j] > pivot);
        do
            i++;
        while (Tab[i] < pivot);
        if (i < j) {
            temp = Tab[i];
            Tab[i] = Tab[j];
            Tab[j] = temp;
        }
        else
            return j;
    }
}

void seg(int *Tab, int p, int r) {
    int q;
    if (p < r) {
        q = part(Tab, p, r);
        seg(Tab, p, q);
        seg(Tab, q+1, r);
    }
}

void tri(int **Tab,int n){
    char choix;
    printf("Choisir la methode de la Tri:\n");
    printf("\t1)Tri par selection\n");
    printf("\t2)Tri par insertion\n");
    printf("\t3)Tri à bulles\n");
    printf("\t4)Tri par segmentation\n> ");
    scanf(" %c",&choix);
    if(choix == '1') selection(Tab,n);
    else if (choix == '2') insertion(Tab,n);
    else if(choix == '3') bulles(Tab,n);
    else if(choix == '4') seg(Tab,0,n);
    else {
        printf("Reponse invalide!!\n");
        tri(Tab,n);
    }
}
int main()
{
    int n;
    while(1){
        init(&n);
        int Tab[n];
        remp(Tab,n);
        tri(Tab,n);
        print_tab(Tab,n);
        printf("Appuyier sur entree pour lancer le programe une autre fois..");
        getch();
    }
    return 0;
}
