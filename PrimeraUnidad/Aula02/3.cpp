/*
* C++ - Listas Enlazadas simples en c++
* Copyright 2014 Martin Cruz Otiniano 
*
* Description: Inserta, elimina, busca, reporta
* Site: martincruz.me
*/

 
#include <iostream>
#include <stdlib.h>
using namespace std;
 
struct nodo{
       int nro;        // en este caso es un numero entero
       struct nodo *sgte;
};
 
typedef struct nodo *Tlista;
 

 
 
void insertarFinal(Tlista &lista, int valor)
{
    Tlista t, q = new(struct nodo);
 
    q->nro  = valor;
    q->sgte = NULL;
 
    if(lista==NULL)
    {
        lista = q;
    }
    else
    {
        t = lista;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = q;
    }
 
}
 
void reportarLista(Tlista lista)
{
 
     while(lista != NULL)
     {
          cout<< lista->nro << " -> ";
          lista = lista->sgte;
     }
}
 
void sumarListas(Tlista lista1,Tlista lista2)
{

    int elevar=0;
    int primerD=0;
    int segundoD=0;
    int suma=0;
    while(lista1!=NULL)
    {

        int suma=lista1->nro + lista2->nro +primerD;
        if(suma>9)
        {
            primerD=suma/10;
            segundoD=suma%10;
            suma=segundoD;
        }
        cout<<suma <<" -> ";
        lista1=lista1->sgte;
        lista2=lista2->sgte;
    }

}
 
int main()
{
    Tlista lista=NULL;
    insertarFinal(lista,3);
    insertarFinal(lista,1);
    insertarFinal(lista,5);
    Tlista lista2=NULL;
    insertarFinal(lista2,5);
    insertarFinal(lista2,9);
    insertarFinal(lista2,2);

    sumarListas(lista,lista2);
}
