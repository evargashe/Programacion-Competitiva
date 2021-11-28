
/* 
https://cses.fi/problemset/task/1653/
 */

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    
    ll n, k; cin>>n>>k;
    vector<ll> matrix(n,0);
    for (ll i = 0; i < n; i++)
        cin>>matrix[i];
    pair<ll, ll> pr[1<<n];
    pr[0] = {0, k+1};
    for (ll s = 1; s < (1<<n); s++) {
        pr[s] = {25, 0};
        for (ll i = 0; i < n; i++) {
            if (s>>i&1){
                auto [c, w] = pr[s^(1<<i)];
                if (w + matrix[i] > k) {
                    c++;
                    w = min(matrix[i], w);
                }
                else
                    w += matrix[i];
                pr[s] = min(pr[s], {c, w});
            }
        }
    }
    cout<<pr[(1<<n)-1].first;
}