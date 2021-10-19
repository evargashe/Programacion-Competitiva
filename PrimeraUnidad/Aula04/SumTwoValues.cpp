
/* https://cses.fi/problemset/task/1640/ */


#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ln '\n';
typedef long long ll;

void SumTwoValues(vector<int>arr,long int len,int suma)
{
    vector<int> aux;

    for( auto i=arr.begin(); i!=arr.end();i++)
        aux.push_back(*i);
    
    sort(aux.begin(),aux.end());

    auto a=aux.begin();
    auto b=aux.end()-1;

    if(aux.size()>1){
        while(*a != *b)
        {
            if( *a + *b > suma)
                b--;
            else if( *a + *b  < suma)
                a++;
            else if( *a + *b == suma);
                break;
        }
        if(*a + *b ==suma)
        {
            for(int i=0;i<len;i++)
            {
                if( arr[i]==*a || arr[i]==*b)
                    cout<<i+1<<" ";
            }
        }
        else{
            cout<<"IMPOSSIBLE";
        }
    }
    else{
        cout<<"IMPOSSIBLE";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    /* int arr[]={1,2,7,9,11,15}; */
    long int len;
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