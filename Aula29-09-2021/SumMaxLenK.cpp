#include <bits/stdc++.h>
using namespace std;


void VentanaDeslizante(int a[], int len,int k)
{
    
    int sumaK=0;
    int suma;
    for(int i=0;i<=len-k;i++)
    {
        suma=0;
        for(int j=i ; j<i+k ; j++)
        {
            suma+=a[j];
        }
        if(suma>sumaK)
            sumaK=suma;
    }
    cout<<"output: "<<sumaK;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[]={2,3,4,1,5};
    /* int len;
    int suma;
    cin>>len>>suma;
    int arr[len]; */
    /* for(int i=0;i<len;i++)
        cin>>arr[i]; */
    int k;
    cin>>k;
    auto len = end(arr) - begin(arr);
    VentanaDeslizante(arr,len,k);

}