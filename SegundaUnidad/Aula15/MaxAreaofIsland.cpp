/* https://leetcode.com/problems/max-area-of-island/
 */
#include <bits/stdc++.h>
#include <numeric>
#include <map>
#include <cmath>
#include <iterator>
#include <deque>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <algorithm>
#include <stack>
#include <climits>


using namespace std;

int m,n;

int DFS( vector<vector<int>>& grid,int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j]!=1) 
        return 0;
    else{
        grid[i][j] = 0;
        return 1  + DFS(grid,i+1, j) + DFS(grid,i, j-1) 
                    + DFS(grid,i, j+1) + DFS(grid,i-1, j);
    }
}


int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        n = grid.size(); 
        m = grid[0].size();
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                if (grid[i][j]==1) 
                    ans = max(ans, DFS(grid,i,j));
        return ans;
}


int main()
{
    vector<vector<int>> grid {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                    {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                    {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                    {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                    {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                    {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                    {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    cout<<maxAreaOfIsland(grid);


}
