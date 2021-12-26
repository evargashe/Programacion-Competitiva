/* 
https://open.kattis.com/problems/pandachess
 */
 
#include <bits/stdc++.h>
using namespace std;

int n, m, d;
map<long long,unordered_set<long long>> lista;
map<long long, int> X;
vector<long long> arr;
unordered_set<long long> matrix;


void Sort(long long u) {
    X[u] = 1;
    for (auto v : lista[u]) {
        if (X[v] == 0) 
            Sort(v);
    }
    arr.push_back(u);
}

int main() {
    cin >> n >> m >> d;
    
    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;        
        lista[a].insert(b);
        matrix.insert(a);
        matrix.insert(b);
    }
    for (auto u : matrix) {
        if (X[u] == 0) Sort(u);
    }
    reverse(arr.begin(), arr.end());

    
    for (int i = 0; i < n; i++) {
        X[arr[i]] = i+1;  
    }
    
    vector<int> v;
    vector<int> L(n, 0);  
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        if (X[a] == 0) 
            continue;
        v.push_back(X[a]);
    }

    int k = 0;  
    for (int i = 0; i < (int) v.size(); i++) {
        int posicion = lower_bound(L.begin(), L.begin() + k, v[i]) - L.begin();
        L[posicion] = v[i];
        if (posicion == k) {
            k++;
        }
    }
    cout << 2*(n - k) << endl;

    return 0;
}