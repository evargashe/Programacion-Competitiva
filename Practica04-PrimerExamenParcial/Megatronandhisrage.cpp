//    https://www.spoj.com/problems/CODFURY/

#include <bits/stdc++.h>
#include <numeric>
#include <map>
#include <math.h>
#include <iterator>
using namespace std;

#define MAX 50000
typedef long long int ll;


void funcion(vector<ll> a,ll len,ll numero)
{

    map<int,int> aux;
    ll suma=0;
    ll p=1;
    int contador=0;
    for(ll i=0 ; i<len ; i++)
    {
        suma+=a[i];
        if(suma < numero){
            contador++;
            aux.insert(pair<int,int>(suma,contador));
        }
        else{
            suma=0;
            contador=0;
        }
    }

    int mayor=0;
    int index=0;
    map<int, int>::iterator i;
    for(i=aux.begin(); i!=aux.end();i++)
    {
        if(mayor < i->first)
        {
            mayor= i->first;
            index= i->second;
        }
    }

    cout<< mayor <<" "<< index;

    
    /* int mayor=0;
    for( auto i=aux.begin(); i!=aux.end();i++)
    {
        if(*i>mayor && *i<numero)
            mayor=*i;
    }
    cout<<"mayor "<<mayor;


    /* ll limite=99999999;
    ll suma=0;
    ll total=0;
    ll cantidad1=0;
    ll cantidad2=0;
    ll max=-1;
    ll mayor=0;
    ll p=1;
    for(ll i=0;i<len;i++)
    {
        suma+=a[i];
        if(suma > numero || suma < 0)
        {
            suma=0;
            cantidad1=0;
            i=i-1;
        }
        if(suma < numero && suma > 0)
        {
            limite = suma;
            cantidad1++;
            cantidad2=cantidad1;
        }
        if(mayor < limite)
        {
            mayor=limite;
        }



    }
    if(cantidad2==0)
        limite = 0;
    if(limite == 99999999)
        cout<<"0 0";
    else
        cout<<limite<<" "<<cantidad2; */
}

signed  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin >> t ;

    while(t > 0)
    {
        ll p,m;
        cin>> p >> m;
        vector<ll> arr(MAX);
        for (ll i = 0; i < p; i++)
        {
            cin>> arr[i];
        }
        funcion(arr,p,m);
        t--;
    }



    
    // int x;
    

    return 0;

} 