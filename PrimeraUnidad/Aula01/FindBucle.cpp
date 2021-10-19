#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <iterator>
#include <vector>
using namespace std;

void bucle(int lista[],int longitud)
{
    for(int i=0;i<longitud-1;i++)
    {
        int aux=lista[i];
        int contador=0;
        for(int j=i;j<longitud-1;j++)
        {
            if( aux == lista[j] )
                contador++;
        }
        if(contador>2)
         {
             cout<< lista[i] << " ";
         }  
    }
}

int main()
{
    int longitud,dato;
    cout<<" tamanio ?" ;
    cin>> longitud ;

    int lista[longitud];

    for(int i=0;i<longitud;i++)
    {
        cin>>dato;
        lista[i]=dato;
        cout<< lista [i] <<" ";
    } 


    cout<< endl;

    bucle(lista,longitud);
    return 0;

    
}









