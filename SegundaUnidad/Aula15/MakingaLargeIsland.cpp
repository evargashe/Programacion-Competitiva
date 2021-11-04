/* 
https://leetcode.com/problems/making-a-large-island/
 */
/* #include <bits/stdc++.h>
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

int DFS(vector<vector<int>> &grid,int i,int j,int numero)
{
    if (i < 0 || j < 0 || i >= grid[0].size() || j >= grid.size() || grid[i][j]!=1) 
        return 0;


    else{
        return 1  + DFS(grid,i+1, j,numero) + DFS(grid,i, j-1,numero) 
                    + DFS(grid,i, j+1,numero) + DFS(grid,i-1, j,numero);
    }
}


int floodfill(vector<vector<int>> &grid)
{
    priority_queue<int> q;
    for(int i=0 ; i<grid.size() ; i++)
    {
        int maxi=0;
        for(int j=0 ; j<grid[0].size() ; j++)
        {
            if(grid[i][j]!=0)
            {
                maxi=max(maxi,DFS(grid,i,j,grid[i][j]));
                q.push(maxi);
            }
        }
    }

    return q.top();
}

int main()
{
    vector<vector<int>> grid {{1,0},
                                {0,1}};

    cout<<floodfill(grid);



}
 */