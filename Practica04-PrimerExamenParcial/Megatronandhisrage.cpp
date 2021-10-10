//    https://www.spoj.com/problems/CODFURY/

/* #include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define MAX 50000
typedef long long int ll;


void funcion(vector<ll> a,ll len,ll numero)
{
    ll suma=0;
    ll total=0;
    ll cantidad=0;
    ll aux=0;
    for(ll i=0;i<len;i++)
    {
        suma += a[i];
        if(suma > numero || suma < 0){
            cantidad=0;
            suma=0;
        }
        if( suma > aux)
        {
            cantidad++;
            aux=suma;
        }
        if( aux < numero && aux > total)
        {

            total=aux; 
            
        }
    }

    cout<<total<<" "<<cantidad;
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

} */