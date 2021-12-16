/* 

https://cses.fi/problemset/task/2108
 */

#include<bits/stdc++.h>
using namespace std;

 
const int maxNum = 1e5+5;

int matrix[maxNum], posicion[maxNum], temporal[maxNum], lcp[maxNum];
int gap, N;
string S;
 
bool compara(int x, int y) {
    if (posicion[x] != posicion[y])
        return posicion[x] < posicion[y];
    x += gap;
    y += gap;
    return (x < N && y < N) ? posicion[x] < posicion[y] : x > y;
}
 
signed main(){
    
    cin>>S; 
    N = S.size();
    for (int i = 0; i < N; i++)
        matrix[i] = i, posicion[i] = S[i];
 
    for (gap = 1;; gap <<= 1) {
        sort(matrix, matrix+N, compara);
        for (int i = 0; i < N-1; i++)
            temporal[i+1] = temporal[i] + compara(matrix[i], matrix[i+1]);
        for (int i = 0; i < N; i++)
            posicion[matrix[i]] = temporal[i];
        if (temporal[N - 1] == N - 1)
            break;
    }
    
    for (int i = 0, k = 0; i < N; i++) 
    if (posicion[i] != N-1) {
        int j = matrix[posicion[i] + 1];
        while (S[i + k] == S[j + k])
            k++;
        lcp[posicion[i]] = k;
        if (k) k--;
    }

    
    int k; 
    cin>>k;
    int prev = 0;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        if (cur + (N-matrix[i]) - prev >= k) {
            int j = prev;
            string ans = S.substr(matrix[i], j);
            while (cur < k) {
                ans += S[matrix[i]+j];
                cur++;
                j++;
            }
            return cout << ans, 0;
        }
        cur += (N-matrix[i]) - prev;
        prev = lcp[i];
    }
}