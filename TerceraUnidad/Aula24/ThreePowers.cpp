/* https://open.kattis.com/problems/threepowers
 */
#include <bits/stdc++.h>
using namespace std;



void solve(int n){
    vector<long long int> v;

    long long int curr=1;
    while(n>0)
    {
        if(n%2==1)
            v.push_back(curr);
        curr*=3;
        n/=2;
    }
    printf("{ ");
    for(int i=0 ; i<v.size(); i++)
    {
        printf("%d",v[i]);
        if(i!=v.size()-1)
            printf(", ");
        printf(" ");

    }
    printf("}\n");
}

int main(){
    while (true)
    {
        int n;
        cin >> n;
        if(n == 0)
            break;
        solve(n-1);
    }
    return 0;
}