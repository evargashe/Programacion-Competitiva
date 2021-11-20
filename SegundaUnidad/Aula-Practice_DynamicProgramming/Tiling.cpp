/* leetcode.com/problems/domino-and-tromino-tiling/
 */

#include <bits/stdc++.h>

using namespace std;
int numTilings(int n) {
    if ( n == 1 ) return 1;
    int mod = 1e9 + 7;
    vector<int> dp(n + 1, 0 );
    dp[1] = 1, dp[2] = 2, dp[0] = 1;
    for ( int i = 3; i <= n; ++i ) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= mod;
        for ( int j = i - 3; j >= 0; --j ) {
            dp[i] += 2 * dp[j];
            dp[i] %= mod;
        }
    }
    return dp[n];
}
int main()
{

    cout<<numTilings(1)<<endl;
    cout<<numTilings(2)<<endl;
    cout<<numTilings(3)<<endl;
    cout<<numTilings(4)<<endl;

    cout<<numTilings(5)<<endl;
    cout<<numTilings(6)<<endl;
    cout<<numTilings(777)<<endl;
    return 0;
}