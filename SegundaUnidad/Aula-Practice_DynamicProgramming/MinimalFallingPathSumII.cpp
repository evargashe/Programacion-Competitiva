#include <bits/stdc++.h>

using namespace std;

int minFallingPathSum(vector<vector<int>>& grid) {
    int m=grid.size(), n=grid[0].size(), i, j;
    vector<int> f=grid[0];
    for(i=1; i<m; i++) {
        auto t=grid[i];
        for(j=0; j<n; j++) {
            int m=INT_MAX;
            for(int k=0; k<n; k++) {
                if (k==j) continue;
                m=min(m, f[k]);
            }
            t[j]+=m;
        }
        f=t;
    }
    return *min_element(f.begin(), f.end());
}

int main()
{
    vector<vector<int>> matrix{{1,2,3},
                    {4,5,6},
                    {7,8,9}};
    cout<<minFallingPathSum(matrix);
}