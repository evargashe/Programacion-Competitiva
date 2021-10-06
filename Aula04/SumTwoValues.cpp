
/* https://cses.fi/problemset/task/1640/ */


#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int> SumTwoValues(vector<int>arr,int len,int suma)
{
    int i;
    vector<int> aux;
    int j;
    int s;
    for(i=0;i<len;i++)
    {
        s=0;
        for( j=len-1; j>i ; j--)
        {
            s=0;
            s=arr[i]+arr[j];
            if(s==suma)
                break;
        }
        if(s==suma)
        {
            aux.push_back(i);
            aux.push_back(j);
            return aux;
            break;
        }
    }
    if(s!=suma)
    {
        cout<<"IMPOSSIBLE";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    /* int arr[]={1,2,7,9,11,15}; */
    int len;
    int suma;
    cin>>len>>suma;
    vector<int> arr;
    int dato;
    for(int i=0;i<len;i++)
    {
        cin>>dato;
        arr.push_back(dato);
    }
    SumTwoValues(arr,len,suma);
     

}