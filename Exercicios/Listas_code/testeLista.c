#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct lista{

    int itens[MAX], n;

}Lista;

Lista* criarLista();
int estaVazia(Lista* l);
int estaCheia(Lista* l);
void inserirElemento(Lista* l, int v);
void imprimeLista(Lista* l);
void removeElemento(Lista* l, int i);

int main(){

    int i = 2;

    Lista* Lista = criarLista();
    estaVazia(Lista); //Esta passando Lista para l
    estaCheia(Lista);
    inserirElemento(Lista, 2);
    inserirElemento(Lista, 3);
    imprimeLista(Lista);
    removeElemento(Lista, i);
    return 0;
}

Lista* criarLista(){
    // Lista* é pq esta armazenando uma lista
    // Lista* l esta declarando l como um ponteiro para lista
    Lista* l = (Lista*)malloc(sizeof(Lista));
    l -> n = 0;

    return l;

}

int estaVazia(Lista* l){
    if(l -> n == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int estaCheia(Lista* l){

    if(l -> n == MAX){
        return 1;
    }
    else{
        return 0;
    }
}

void inserirElemento(Lista* l, int v){
    if( !estaCheia(l)){
        l -> itens[l -> n] = v;
        l -> n++;
    }
    else{
        printf("Lista cheia!\n");
        exit(1);
    }
}

void imprimeLista(Lista* l){
    
    int i;

    if(!estaVazia(l)){
        for(i = 0; i < l -> n; i++){
        printf("%d ", l -> itens[i]);
    }
    printf("\n");
    }
    else{
    printf("Lista vazia!\n");
    }
}

void removeElemento(Lista* l, int i){
    if(!estaVazia(l) && (i > 0 && i <= MAX)){
        for(int x = i; x < l->n; x++){
            l->itens[x-1] = l->itens[x];
            l->n--;
        }
    }
    else{
        printf("...");
}
}
