#include <bits/stdc++.h>
#include <vector>
#include <numeric>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[]={1,2,3,4,5,6};
    auto array_length = end(arr) - begin(arr);
    int aux[array_length+1];
    aux[0]=0;
    int pos=1;
    for(int i=0; i<array_length ;i++)
    {
        int sum=0;
        for(int j=0; j<=i ;j++)
        {
            sum+=arr[j];
        }
        aux[pos]=sum;
        pos++;

    }

    for(int i=0; i<array_length+1;i++)
    {
        cout<<aux[i]<<" ";
    } 
    
}