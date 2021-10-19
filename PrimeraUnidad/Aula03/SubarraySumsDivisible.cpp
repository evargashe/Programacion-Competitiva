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
    for(int i=0;i<array_length;i++)
    {
        for(int j=i;j<array_length;j++)
        {
            int suma=0;
            for(int l=i;l<j+1;l++)
            {
                suma+=arr[l];
            }
            if(suma%k==0){
                contador++;
            }
        }
    }
    cout<<contador;


}