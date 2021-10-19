

/* https://cses.fi/problemset/task/1643/
 */

#include <bits/stdc++.h>
using namespace std;
bool esNegativo(int a[],int len)
{
    bool es=false;
    for(int i=0;i<len;i++)
    {
        if(a[i]<0)
            es=true;
        else{
            es=false;
            break;
        }
    }
    return es;
}

void VentanaDeslizante(int a[], int len)
{
    int suma=0;
    int mayor=a[0];
    if(esNegativo(a,len)==true)
    {
        for(int i=0;i<len;i++)
        {
            if(a[i]>mayor)
                mayor=a[i];
        }
    }

    else{
        for(int i=0;i<len;i++)
        {
            suma+=a[i];
            if(suma<0){

                suma=0;

            }
            if(suma>mayor)
            {
                mayor=suma;
            }
        }

    }
    cout<<mayor;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tam;

    cin>>tam;
    int arr[tam];
    for(int i=0;i<tam;i++)
        cin>>arr[i];

    VentanaDeslizante(arr,tam);
    return 0;

}
