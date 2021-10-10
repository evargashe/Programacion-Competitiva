/* https://cses.fi/problemset/task/2074 */

#include <bits/stdc++.h>
#include <numeric>
using namespace std;


typedef long long int ll;


void funcion1(vector<ll> &arr,ll a,ll b)
{
    reverse(arr.begin()+a-1,arr.begin()+b);

    /* for(auto i=arr.begin(); i!=arr.end();i++)
    {
        cout<<*i<<" ";
    } */
}
ll funcion2(vector<ll> arr,ll a,ll b)
{
    ll sum = 0;
    sum=std::accumulate(arr.begin()+a-1,arr.begin()+b,0);
    return sum;
}

signed  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(200000);
    // int x;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> datos;
    while(m>0)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            ll a;
            ll b;
            cin>>a>>b;
            funcion1(arr,a,b);
        }
        if(t==2)
        {
            ll a;
            ll b;
            cin>>a>>b;
            ll suma=funcion2(arr,a,b);
            if(suma!=0)
                datos.push_back(suma);
        }
        m--;
    }
    for(auto i=datos.begin(); i!=datos.end();i++)
    {
        cout<<*i<<endl;
    }
    return 0;

}