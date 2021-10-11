/* //   https://www.spoj.com/problems/ADASQR/

#include <bits/stdc++.h>
#include <numeric>
#include <map>
#include <math.h>
#include <iterator>
using namespace std;

const int MAX = 5005;
typedef long long int ll;
long long table[MAX][MAX];

int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x0,a,b,c;

    int N,K;
    cin>>N,K;

    for( int i=1; i<=N ; i++)
    {
        cin>>x0>>a>>b>>c;
        table[i][1]=x0;
    }

    for( int i=1; i<=N ; i++)
    {
        for( int j=1 ; j<=N ;j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }

    
    return 0;

}  */