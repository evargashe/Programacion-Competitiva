/* https://www.spoj.com/problems/ADAPLANT/ */


#include <bits/stdc++.h>
#include <math.h>
#include <numeric>
using namespace std;


typedef long long int ll;



int funcion(vector<ll> a,ll len,ll k)
{
    int mayor=0;
    int diferencia=0;
    for(int i=0 ; i<len-1; i++)
    {
        diferencia=fabs((a[i]-a[i+1]));
        if(diferencia > k && mayor < diferencia){
            mayor=diferencia;
            
        }
    }
    return mayor;
}

signed  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin >> t ;
    vector<ll> aux;
    ll a=t;
    while(t > 0)
    {
        ll n,k;
        cin>> n >> k;
        vector<ll> arr(300025);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll x=funcion(arr,n,k);
        aux.push_back(x);
        t--;
    }

    for (ll i=0 ; i<a ; i++)
    {
        cout<<aux[i]<<endl;
    }
    return 0;
}