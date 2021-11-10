/* 
https://open.kattis.com/problems/10kindsofpeople
 */
#include <bits/stdc++.h>

using namespace std;
/* 
10 20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1
0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
3
2 3 8 16
8 1 7 3
1 1 10 20 


1 4
1 1 0 0
2
1 1 1 4
1 1 1 1

*/

int DFS(vector<vector<int>> &grid,int i,int j,int x ,int y,int valor){
    if (i == x && j == y) return 1;
    
    int sym=grid[i][j];

    grid[i][j]=4;
    return ((i     > 0 && grid[i - 1][j]== sym && DFS(grid, i - 1, j,     x, y,valor))
        ||  (i + 1 < grid.size() && grid[i + 1][j]== sym && DFS(grid, i + 1, j,     x, y,valor))
        ||  (j     > 0 && grid[i][j - 1] == sym && DFS(grid, i,     j - 1, x, y,valor))
        ||  (j + 1 < grid[0].size() && grid[i][j + 1]== sym && DFS(grid, i,     j + 1, x, y,valor)));

}
void KindofPeople(vector<vector<int>> &grid, int i,int j,int x,int y)
{

    
    int sym=grid[i-1][j-1];
    if (sym != grid[x-1][y-1])
            cout<<"neither\n";
    else if(DFS(grid,i-1,j-1,x-1, y-1,grid[i-1][j-1]))
        printf(sym==1 ? "decimal\n" : "binary\n");
    else
        cout<<"neither\n";
        
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid;
    for (int i = 0; i < n; i++) {
        vector<int> v1;
  
        for (int j = 0; j < m; j++) {
            int num;
            cin>>num;
            v1.push_back(num);
        }
        grid.push_back(v1);
    }
    /* for(int i=0 ; i<n ;i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    } */
    int K;
    cin>>K;
    while(K--)
    {
        int i,j,x,y;
        cin>>i>>j>>x>>y;
        KindofPeople(grid,i,j,x,y);
    }
    return 0;
}