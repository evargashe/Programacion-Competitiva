
#include <iostream>
using namespace std;


void productoMaximo(int lista[],int cantidad)
{
    int max=0;
    int penultimo=0;
    for(int j=0;j<cantidad;j++)
    {
        if(lista[j] > max){
			max = lista[j];
            j=0;
		}
        if(lista[j]!=max){
            if(lista[j] > penultimo){
                penultimo = lista[j];
            }    
        }
    }
    cout<< " mayor "<< endl;
    cout<< max <<endl;
    cout<< " penultimo "<<endl;
    cout<< penultimo <<endl;

    cout<<" multiplicador maximo = " << max*penultimo ;
}
int main()
{


    /* PRIMER EJERCICIO */
    int cantidad,dato;
    int i=0;
    cout<<"tamanio de la lista ? ";
    cin>>cantidad;
    int lista[cantidad];
    for(int k=0;k<cantidad;k++)
    {
        cin>>dato;
        lista[k]=dato;
    }


    for(int j=0;j<cantidad;j++)
    {
        cout<<lista[j]<<" ";
    }
    cout<<endl;

    productoMaximo(lista, cantidad);
    
    /* SEGUNDO EJERCICIO */
    
    
    

}