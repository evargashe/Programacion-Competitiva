
/* https://leetcode.com/problems/min-cost-climbing-stairs/
 */

#include <bits/stdc++.h>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    for(int i=cost.size()-3; i>=0 ; i--)
    {
        cost[i]+=min(cost[i+1],cost[i+2]);
    }
    return min(cost[0],cost[1]);
}
int main()
{
    vector<int> cost{1,100,1,1,1,100,1,1,100,1};

    cout<<minCostClimbingStairs(cost);
    return 0;
}