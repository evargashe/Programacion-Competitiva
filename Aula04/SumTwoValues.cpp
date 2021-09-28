#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    /* int arr[]={1,2,7,9,11,15}; */
    int len;
    int suma;
    cin>>len>>suma;
    int arr[len];
    for(int i=0;i<len;i++)
        cin>>arr[i];
     

    int *pointer1=&arr[0];
    int *pointer2=&arr[len-1];
    int contador;
    int posicionLeft=1;
    int posicionRight=len;
    while(posicionRight>posicionLeft)
    {
        contador=(*pointer2)+(*pointer1);
        if(contador>suma){
            pointer2--;
            posicionRight--;
        }
        else if(contador<suma){
            pointer1++;
            posicionLeft++;
        }
        else if(suma==contador){
            cout<<"output"<<"["<<posicionLeft<<"]"<<","<<"["<<posicionRight<<"]";
            break;
        }


    }

   
}