#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int arr[]={1,7,3,6,5,6};
    //int arr[]={1,2,3};
    int arr[]={2,1,-1};
    auto array_length = end(arr) - begin(arr);
    int i=0;
    bool esta=false;
    for(; i<array_length;i++)
    {
        int sumLeft=0;
        int sumRight=0;
        int j=0;
        int k=i+1;
        for(; j<i ;++j)
        {
            sumLeft+=arr[j];
        }
        for(; k<array_length ;++k )
        {
            sumRight+=arr[k];
        }
        if(sumLeft==sumRight){
            esta=true;
            break;
        }
    }
    if(esta)
    {
        cout<< i ;
    }
    else{
        cout<< "-1";
    }


}