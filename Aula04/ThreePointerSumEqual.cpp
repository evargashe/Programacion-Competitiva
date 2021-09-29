#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    /* int arr[]={1,2,7,9,11,15}; */
    int arr[]={1,2,4,5,12}; 
    auto len = end(arr) - begin(arr);

    int suma=17;
    int contador=0;
    
    for(int i=0;i<len;i++){
        int primero=arr[i];
        int *pointer1=&arr[len/2];
        int *pointer2=&arr[len-1];
        int posicionRight=len-1;
        int posicionMid=len/2;
        while(suma!=contador && posicionRight<len && posicionMid<len)
        {
            contador=primero+(*pointer1)+(*pointer2);
            if(contador>suma)
            {
                pointer2--;
                posicionRight--;
            }
            else if(contador<suma){

                pointer1++;
                posicionMid++;
            }
            if(suma==contador){
            cout<<"output"<<"["<<i<<"]"<<"["<<posicionMid<<"]"<<"["<<posicionRight<<"]";
            break;
        }

        }
        
    }


        
    
     

}