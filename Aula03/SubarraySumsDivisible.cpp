#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[]={4,5,0,-2,-3,1};
    auto array_length = end(arr) - begin(arr);
    int k;
    cin>>k;
    int contador=0;
    for(int i=1;i<=array_length;i++)
    {
        int aux[i];
        if(i==1)
        {
            for(int j=0;j<array_length;j++)
            {
                if(arr[j]%k==0){

                    contador++;
                }
            }
        }
        else{
            int j=i-1;
            int m=0;
            while(j<array_length)
            {
                int suma=0;
                for(int i=0;i<=j;i++)
                {
                    suma+=arr[i];
                }
                if(suma%k==0)
                {
                    contador++;
                }
                m++;
                j++;     
            }       

        }
    }
    cout<<contador;


}