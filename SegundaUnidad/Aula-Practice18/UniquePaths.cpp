
/* https://leetcode.com/problems/unique-paths/
 */
#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) 
{
    
    vector<vector<int>> dp(m, std::vector<int>(n, 0));
    dp[0][0]=5;
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {   
            if(j==n-1&&i==m-1) 
                dp[i][j]=1;
            else if(i==m-1) 
                dp[i][j]=dp[i][j+1];
            else if(j==n-1) 
                dp[i][j]=dp[i+1][j];
            else 
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
        }
    }
    return dp[0][0];
}

int main()
{
    cout<<uniquePaths(3,7);
    return 0;
}