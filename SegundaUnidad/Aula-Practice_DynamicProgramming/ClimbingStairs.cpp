/* https://leetcode.com/problems/climbing-stairs/submissions/
 */
#include <bits/stdc++.h>

using namespace std;

int climbStairs(int n) {
    if(n<=2) return n;
    vector<int> dp;
    dp.push_back(1);
    dp.push_back(1);
    for(int i=2; i<=n; i++){
        dp.push_back(dp[i-1]+dp[i-2]);
    }
    return dp[n];
}


int main()
{

    cout<<climbStairs(5);
    return 0;
}