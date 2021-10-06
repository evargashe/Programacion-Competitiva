#include <bits/stdc++.h>
using namespace std;


/* Sizeof thesmallestcontiguoussubarraywitha 
sum greaterthanorequaltoS
Input: [2, 4, 2, 5, 1]
S: 7
Output: 2 */


void VentanaDeslizante(int a[], int len,int k)
{
    int suma;
    for(int i=1;i<len;i++)
    {
        for(int j=0;j<=len-i;j++)
        {
            suma=0;
            for(int m=j ; m<j+i ; m++)
            {
                suma+=a[m];
            }
            if(suma==k)
            {
                cout<<i;
                break;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[]={2,4,2,5,1};
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