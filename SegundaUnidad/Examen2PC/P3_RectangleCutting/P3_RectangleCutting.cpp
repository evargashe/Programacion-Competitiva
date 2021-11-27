/* 
https://cses.fi/problemset/task/1744
 */
#include <bits/stdc++.h>

using namespace std;
const int aux = 0x3f3f3f3f;


int A, B, matrix[501][501];

int rectangleCutting(int a, int b){
    if(a > b)   
    {
        int k=a;
        a=b;
        b=k;
    }
    if(matrix[a][b] != aux)     
        return matrix[a][b];
    if(a == b)              
        return matrix[a][b] = 0;
    if(a == 1 || b == 1)    
        return matrix[a][b] = (b== 1 ? a-1 : b-1);
    for(int i = 1; i < b; i++)
        matrix[a][b] = min(matrix[a][b], rectangleCutting(a, i) + rectangleCutting(a, b-i) + 1);
    for(int i = 1; i < a; i++)
        matrix[a][b] = min(matrix[a][b], rectangleCutting(i, b) + rectangleCutting(a-i, b) + 1);
    return matrix[a][b];
}

int main(){
    memset(matrix, 0x3f, sizeof(matrix));
    cin>>A>>B;
    cout<<rectangleCutting(A,B);
}