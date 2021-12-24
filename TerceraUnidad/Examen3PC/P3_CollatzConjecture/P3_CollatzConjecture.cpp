/* https://open.kattis.com/problems/collatz
 */
#include <bits/stdc++.h>
using namespace std;


long long collazt(long long &  a) {
    if (a % 2 == 0) return  a /= 2;
    else return a = 3 * a + 1;
}

void solve(long long A,long long B)
{
    std:unordered_map<long long,long long> c;
    long long a=A;
    long long at=B;
    long long i=0;
    c[a]=i++;
    while(a!=1)
    {
        collazt(a);
        c[a]=i++;
    }
    long long steps=0;
    while(!c.count(at))
    {
        collazt(at);
        ++steps;
    }
    long long steps2=c[at];
    cout<<A<<" needs " << steps2 <<" steps, " ;
    cout<<B<<" needs " << steps <<" steps, " ;
    cout<<"they meet at "<< at << "\n";

}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    long long A,B;
    while(cin>>A>>B && A && B)
    {
        solve(A,B);
    }
    return 0;
}