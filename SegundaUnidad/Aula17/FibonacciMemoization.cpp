#include <bits/stdc++.h>

using namespace std;


long fib(int n,vector<long> &memo)
{
    if(memo[n])
        return memo[n];
    long result{};
    if(n<=1)
        result=n;
    
    else
        result=fib(n-2,memo)+fib(n-1,memo);
    memo[n]=result;
    return result;

}

long  fib_memoization(int n)
{
    vector<long>memo(n+1);
    return fib(n,memo);
}

int main()
{
    cout<<fib_memoization(1000);
    return 0;
    
}