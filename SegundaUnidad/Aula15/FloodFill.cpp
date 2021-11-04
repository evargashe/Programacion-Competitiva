/* https://leetcode.com/problems/flood-fill/submissions/
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

void floodfillUtil(vector<vector<int>> &image,int sr,int sc,int numero,int newColor)
{
    if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size())
        return;
    if(image[sr][sc]!=numero)
        return;
    if(image[sr][sc]==newColor)
        return;

    image[sr][sc]=newColor;
    floodfillUtil(image, sr+1, sc, numero, newColor);
    floodfillUtil(image, sr-1, sc, numero, newColor);
    floodfillUtil(image, sr, sc+1, numero, newColor);
    floodfillUtil(image, sr, sc-1, numero, newColor);
}

vector<vector<int>> floodfill(vector<vector<int>> &image,int sr,int sc,int newColor)
{
    if(image[sr][sc]==newColor)
        return image;

    floodfillUtil(image,sr,sc,image[sr][sc],newColor);
    return image;
}

int main()
{
    vector<vector<int>> grid {{1,1,1},
                                {1,1,0},
                                {1,0,1}};

    vector<vector<int>> salida=floodfill(grid,1,1,2);

    for (int i=0; i<salida.size(); i++)
    {
        for (int j=0; j<salida[0].size(); j++)
           cout << salida[i][j] << " ";
        cout << endl;
    }


}
