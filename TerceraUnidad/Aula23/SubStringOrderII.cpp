/* https://cses.fi/problemset/task/2109
 */
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
#define F first
#define S second
 
const int mxN = 1e5+5;
int matriz[mxN], posicion[mxN], temporal[mxN], lcp[mxN];
int gap, N;
string S;
 
bool comp(int x, int y) {
    if (posicion[x] != posicion[y])
        return posicion[x] < posicion[y];
    x += gap;
    y += gap;
    return (x < N && y < N) ? posicion[x] < posicion[y] : x > y;
}
 

pair<int,int> seg[mxN*10];
int mark[mxN*10];
 
void insertar(int k) {
    if (mark[k]) {
        mark[k] = 0;
        seg[2*k].F = seg[2*k + 1].F = seg[k].F/2;
        seg[2*k].S = seg[2*k + 1].S = 0;
        mark[2*k] = mark[2*k + 1] = 1;
    }   
}
 
void actualizar(int v, int a, int b, int k, int x, int y) {
    if (b < x || a > y) return;
    if (a<=x && b>=y) {
        seg[k].S += v;
        return;
    }
    int h = min(b,y) - max(a,x) + 1;
    insertar(k); 
    seg[k].F += h*v;
    int d = (x+y)/2;
    actualizar(v, a, b, 2*k, x, d);
    actualizar(v, a, b, 2*k + 1, d + 1, y);
}
int asignar(int v, int a, int b, int k, int x, int y) {
    if (b < x || a > y) return seg[k].F + (y - x + 1)*seg[k].S;
    if (a <= x && b >= y) {
        seg[k].F = (y-x+1)*v;
        seg[k].S = 0;
        mark[k] = 1; 
        return seg[k].F;
    }


    insertar(k); 
    int d = (x+y)/2;
    seg[2*k].S += seg[k].S,  seg[2*k + 1].S += seg[k].S;
    seg[k].S = 0;
    seg[k].F = asignar(v, a, b, 2*k, x, d) + asignar(v, a, b, 2*k + 1, d + 1, y);
    return seg[k].F;
 
}
int sumar(int a, int b, int k, int x, int y) {
    if (b < x || a > y) return 0;
    if (a <= x && b >= y) {
        return seg[k].F + (y-x+1)*seg[k].S;
    }
    insertar(k); 
    seg[k].F += (y-x+1)*seg[k].S;
    seg[2*k].S += seg[k].S, seg[2*k + 1].S += seg[k].S;
    seg[k].S = 0;
    int d = (x+y)/2;
    return sumar(a, b, 2*k, x, d) + sumar(a, b, 2*k + 1, d + 1, y);
}


signed main(){
     
    cin>>S; N = S.size();

    //suffix
    for (int i = 0; i < N; i++)
        matriz[i] = i, posicion[i] = S[i];
 
    for (gap = 1;; gap <<= 1) {
        sort(matriz, matriz+N, comp);
        for (int i = 0; i < N-1; i++)
            temporal[i+1] = temporal[i] + comp(matriz[i], matriz[i+1]);
        for (int i = 0; i < N; i++)
            posicion[matriz[i]] = temporal[i];
        if (temporal[N - 1] == N - 1)
            break;
    }

    //LCP
    for (int i = 0, k = 0; i < N; i++) if (posicion[i] != N-1) {
        int j = matriz[posicion[i] + 1];
        while (S[i + k] == S[j + k])
            k++;
        lcp[posicion[i]] = k;
        if (k) k--;
    }


    int k; cin>>k;

    k = N*(N+1)/2 - k + 1; 
    int K = 1<<(int) ceil(log2(N+1));
    int cur = 0;
    for (int i = N-1; i >= 0; i--) {
        actualizar(1, 1, N-matriz[i], 1, 0, K-1);
        int prev = (i ? lcp[i-1] : 0);
        int l = prev+1, r = N-matriz[i];
        int ans = -1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (cur + sumar(m, N-matriz[i], 1, 0, K-1) >= k) {
                ans = m; l = m + 1;
            }
            else r = m - 1;
        }
        if (ans != -1) {
            return cout << S.substr(matriz[i], ans), 0;
        }
        cur += sumar(prev+1, N-matriz[i], 1, 0, K-1);
        asignar(0, prev+1, N-matriz[i], 1, 0, K-1);
    }
}