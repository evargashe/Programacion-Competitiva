/* http://www.usaco.org/index.php?page=viewproblem2&cpid=104&lang=es
 */
#include <bits/stdc++.h>
#include <numeric>
#include <map>
#include <math.h>
#include <iterator>
#include <deque>
#include <vector>

using namespace std;


int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int N;
    long long K;
    cin>>N;cin>>K;

    vector<int> arr(N);
    while(K--)
    {
        int A,B;
        cin>>A;cin>>B;
        A--;
        B--;
        arr[A]++;
        arr[B+1]--;
    }
    int salida[N];
    int aux=0;
    int i=0;
    while(i<N)
    {
        cout<<aux<<" ";
        aux+=arr[i];
        salida[i]=aux;
        i++;
    }
    cout<<endl;
    sort(salida,salida+N);

    cout<<salida[N/2];
    return 0;
}  
