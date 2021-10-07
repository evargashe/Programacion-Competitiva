
/* https://cses.fi/problemset/task/1640/ */


#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;

#define ln '\n';
typedef long long ll;

int SumThreeValues(vector<pair<int,int>> a,long int len,int suma)
{

    vector<pair<int,int>> aux;

    for( auto i=a.begin();i!=a.end();i++)
    {
        aux.push_back(make_pair(i->first,i->second));
    }


    sort(aux.begin(),aux.end());

    int m=1;
    for(auto i=aux.begin(); i!=aux.end();i++,m++)
    {
        auto j=aux.begin()+m;
        auto k=aux.end()-1;

        while(j<k)
        {
            if(i->first + j->first + k->first >suma)
            {
                k--;
            }
            else if( i->first + j->first + k->first  <suma )
            {
                j++;
            }
            else if( i->first + j->first + k->first == suma )
            {
                cout<< i->second +1 <<" "<< j->second  +1 <<" "<< k->second +1 ;
                return 0;
          
            }
        }


    }
    cout<<"IMPOSSIBLE";
    
    /* vector<int> aux;

    for( auto i=arr.begin(); i!=arr.end();i++)
        aux.push_back(*i);
    
    ort(aux.begin(),aux.end());

    int i;
    if(aux.size()>3){
        int a;
        int b;

        for(i=0;i<len;i++)
        {
            a=i+1;
            b=len-1;
            while(a<b)
            {
                if( aux[i] + aux[a] + aux[b] > suma)
                    b--;
                else if(
                     aux[i] + aux[a] + aux[b]  < suma)
                    a++;
                else if( aux[i] + aux[a] + aux[b] == suma);
                    break;
            }
            if( aux[i] + aux[a] + aux[b] == suma);
                break;
        }
        if(aux[i] + aux[a] + aux[b] ==suma)
        {
            for(int j=0;j<len;j++)
            {
                if(arr[j]==aux[i] || arr[j]==aux[a] || arr[j]==aux[b])
                    cout<<j+1<<" ";
            }
        }
        else{
            cout<<"IMPOSSIBLE";
        }
    }
    else if(aux.size()==3)
    {
        if(aux[0]+aux[1]+aux[2]==suma)
            cout<< 1 <<" "<<2<<" "<<3;
        else
            cout<<"IMPOSSIBLE";
    }
    else{
        cout<<"IMPOSSIBLE";
    }  */
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    /* int arr[]={1,2,7,9,11,15}; */
    /* long int len;
    int suma;
    cin>>len>>suma;
    vector<int> arr;
    int dato;
    for(int i=0;i<len;i++)
    {
        cin>>dato;
        arr.push_back(dato);
    }
    SumTwoValues(arr,len,suma); */

    /* int suma,len;
    cin>>len>>suma;
    int dato;
    vector<map<int,int>> a;
    vector<int> arr;
    for(int i=1;i<=len;i++){
        cin>>dato;
        map.insert
        arr.push_back(a);     
    }
    for( auto i=a.begin(); i!=a.end();++i)
    {
        cout<<i->first
            <<'\t'<<i->second <<"\n";
    } */

    int suma,len;
    cin>>len>>suma;
    vector<pair<int,int>> a;
    int dato;
    for( int i=0;i<len;i++)
    {
        cin>>dato;
        a.push_back(make_pair(dato,i));
    }
    SumThreeValues(a,len,suma);
    
}