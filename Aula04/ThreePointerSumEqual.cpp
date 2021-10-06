
/* https://cses.fi/problemset/task/1641
 */

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len;
    cin>>len;
    int suma;
    cin>>suma;

    int arr[len];
    for(int i = 0; i<len ;i++)
        cin>>arr[i];

    
    

    if(len==1){
        cout<<"IMPOSSIBLE";
    }
    else{
        int primero,segundo,tercero;
        int contador;
        for(int i=0; i<len/2 ;i++){
            primero=i;
            for(int j=i+1; j<len ; j++)
            {
                for(int k= len-1; k>j ; k--){
                    contador=0;
                    contador=arr[i]+arr[j]+arr[k];
                    if(contador==suma)
                    {
                        tercero=k;
                        break;
                    }
                } 
                if(contador==suma)
                {
                    segundo=j;
                    break;
                }

            } 
            if(contador==suma)
            {
                break;
            }
            
        }
        if(suma==contador)
            cout<<primero+1<<" "<<segundo+1<<" "<<tercero+1;
        else{
            cout<<"IMPOSSIBLE";
        }    
    }
}