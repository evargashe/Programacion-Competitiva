/* 

https://cses.fi/problemset/task/2108
 */

#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
 
const int tamañoMaximo = 1e5+5;
int sa[tamañoMaximo], pos[tamañoMaximo], tmp[tamañoMaximo], lcp[tamañoMaximo];
int gap, N;

 
bool comparar(int x, int y) {
    if (pos[x] != pos[y])
        return pos[x] < pos[y];
    x += gap;
    y += gap;
    return (x < N && y < N) ? pos[x] < pos[y] : x > y;
}
 
void suffix(string S) {
    for (int i = 0; i < N; i++)
        sa[i] = i, pos[i] = S[i];
 
    for (gap = 1;; gap <<= 1) {
        sort(sa, sa+N, comparar);
        for (int i = 0; i < N-1; i++)
            tmp[i+1] = tmp[i] + comparar(sa[i], sa[i+1]);
        for (int i = 0; i < N; i++)
            pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1)
            break;
    }
}
 
void construir_lcp(string S) {
    for (int i = 0, k = 0; i < N; i++) 
        if (pos[i] != N-1) {
            int j = sa[pos[i] + 1];
            while (S[i + k] == S[j + k])
                k++;
            lcp[pos[i]] = k;
            if (k) k--;
        }
}
 
signed main(){
 
    string S;
    cin>>S; 
    N = S.size();
    suffix(S);
    construir_lcp(S);
    int k; cin>>k;
    int prev = 0;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        if (cur + (N-sa[i]) - prev >= k) {
            int j = prev;
            string ans = S.substr(sa[i], j);
            while (cur < k) {
                ans += S[sa[i]+j];
                cur++;
                j++;
            }
            return cout << ans, 0;
        }
        cur += (N-sa[i]) - prev;
        prev = lcp[i];
    }
}