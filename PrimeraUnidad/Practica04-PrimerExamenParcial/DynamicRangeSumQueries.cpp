

/* https://cses.fi/problemset/task/1648/
 */

#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
const int NMAX = 200005;
vector<ll> arr(NMAX);


void funcion1(vector<ll> &nums,int k,int  u){

    nums[k-1] = u;
}

ll funcion2(vector<ll> nums, int a, int b){

    ll sum = 0;
    sum=std::accumulate(nums.begin()+a-1,nums.begin()+b,0);
    return sum;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    // int x;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> dato;
    while (q--)
    {
        int x;
        cin >> x ;
        if(x==1){
            int y;
            ll z;
            cin>>y>>z;
            funcion1(arr,y,z);
        }

        if(x==2){
            int y;
            int z;
            cin>>y>>z;
            ll ans = funcion2(arr,y,z);
            if(ans!=0)
                dato.push_back(ans);
        }
        
    }
    for (auto i = dato.begin(); i!=dato.end(); i++)
    {
        cout<< *i<<endl;;
    }
    return 0;

}