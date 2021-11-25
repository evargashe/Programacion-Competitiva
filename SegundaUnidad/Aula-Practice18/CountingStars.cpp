/* https://open.kattis.com/problems/countingstars
 */

#include <bits/stdc++.h>
using namespace std;

int mymap[110][110] = {{0}};
int visited [110][110] = {{0}};
int stars = 0;
int max_ROW, max_COL;

void flood(int i, int j){
    if(i < 0 || i == max_ROW || j < 0 || j == max_COL || mymap[i][j] || visited[i][j]) return;
    else{
        visited[i][j] = 1;
        flood(i, j+1);
        flood(i, j-1);
        flood(i+1, j);
        flood(i-1, j);
    }
}

void clear_everything(){
    memset(mymap, 0, sizeof(mymap));
    memset(visited, 0, sizeof(mymap));
}

int main() {
    int i, j, index = 0;
    string pixels;
    
    while(cin >> max_ROW >> max_COL){
        index++;
        getline(cin, pixels); //flush, so no \n to deal with
        
        for(i = 0; i < max_ROW; i++){
        getline(cin, pixels);
        for(j = 0; j < pixels.size(); j++){
            if(pixels[j] == '#') mymap[i][j] = 1;
            else mymap[i][j] = 0;
        }
        }
        for(i = 0; i < max_ROW; i++){
        for(j = 0; j < max_COL; j++){
            if(mymap[i][j] == 0 && visited[i][j] == 0){
            stars++;
            flood(i, j);
            }
        }
        }
        cout << "Case " << index << ": " <<  stars << endl;
        clear_everything();
        stars = 0;
    }
    return 0;
}