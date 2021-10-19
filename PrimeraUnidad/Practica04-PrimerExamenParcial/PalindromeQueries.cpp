

/* https://cses.fi/problemset/task/2420
 */

#include <bits/stdc++.h>
#include <numeric>
using namespace std;
const int NMAX = 200005;
#define int long long
vector<char> arr(NMAX);


void funcion1(vector<char> &nums,int k,char  u){

    nums[k-1] = u;
}

bool funcion2(vector<char> nums ,int a, int b){
    bool es=false;
    for(int i=a-1, j=b-1; i <=j ;i++,j--)
    {
        if(nums[i]==nums[j])
            es=true;
        else{
            es=false;
            break;
        }
    }
    return es;
}

signed  main()
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
    vector<string> dato;
    while (q--)
    {
        int x;
        cin >> x ;
        if(x==1){
            int y;
            char z;
            cin>>y>>z;
            funcion1(arr,y,z);
        }

        if(x==2){
            int y;
            int z;
            cin>>y>>z;
            bool ans = funcion2(arr,y,z);
            if(ans==true)
                dato.push_back("YES");
            else{
                dato.push_back("NO");
            }

        }
        
    }
    for (auto i = dato.begin(); i!=dato.end(); i++)
    {
        cout<< *i<<endl;;
    }
    return 0;

}