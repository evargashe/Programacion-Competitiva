//   https://www.spoj.com/problems/ADASQR/

#include <bits/stdc++.h>
#include <numeric>
#include <map>
#include <math.h>
#include <iterator>
#include <deque>


using namespace std;

const int MAX = 5005;
const int MODULO = 1000000007;
long long table[MAX][MAX];
long long minimumInRow[MAX][MAX];


void add(deque<long long> &dq, long long value) {
    while (!dq.empty() && dq.back() > value) dq.pop_back();
    dq.push_back(value);
}
void remove(deque<long long> &dq, long long value) {
    if (!dq.empty() && dq.front() == value) dq.pop_front();
}

int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    int N,K;
    cin>>N;cin>>K;

    for( int i=0; i<N; i++)
    {
        long long x0,a,b,c;
        cin>>x0;cin>>a;cin>>b;cin>>c;
        table[i][0]=x0;
        for(int j=1;j<N;j++)
            table[i][j]= (table[i][j-1]*a+b)%c;
    }

    for( int i=0; i<N ; i++)
    {
        for( int j=0 ; j<N ;j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }
    for (int i = 0; i < N; i++) {
        deque<long long> activeMinimums;
        for (int j = 0; j < N; j++) {
            if (j > K-1) remove(activeMinimums,table[i][j - K-1]);
            add(activeMinimums, table[i][j]);
            minimumInRow[i][j] = activeMinimums.front();
        }
    }
     long long result = 0;
    for (int j = K; j <= N; j++) {
        deque<long long> activeMinimums;
        for (int i = 0; i <= N; i++) {
            if (i > K-1) remove(activeMinimums, minimumInRow[i - K-1][j]);
            add(activeMinimums, minimumInRow[i][j]);
            if (i >= K-1) result = (result + activeMinimums.front()) % MODULO;
        }
    }
    printf("%lld\n", result);


    return 0;
}
