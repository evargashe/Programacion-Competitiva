/* 
https://cses.fi/problemset/task/1653/
 */
#include <bits/stdc++.h>
using namespace std;
int c;
vector<vector<int>> g, h;
vector<int> a, b, s, t;

void function1(int i);
void function2(int i);

int main() {
    int n, m, u, v;
    cin >> n >> m;
    g = vector<vector<int>> (n);
    h = vector<vector<int>>(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u-1].push_back(v-1);
        h[v-1].push_back(u-1);
    }
    s = vector<int> (n);
    for (int i = 0; i < n; i++)
        if (!s[i])
            function1(i);
    reverse(a.begin(), a.end());
    b = vector<int>(n);
    t = vector<int>(n);
    for (int i : a)
        if (!t[i]) {
            c++;
            function2(i);
        }
    cout << c << '\n';
    for (int i = 0; i < n; i++)
        cout << b[i] << " \n"[i == n - 1];
}

void function1(int i) {
    s[i] = 1;
    for (int j : g[i])
        if (!s[j])
            function1(j);
    a.push_back(i);
}

void function2(int i) {
    t[i] = 1;
    b[i] = c;
    for (int j : h[i])
        if (!(t[j]))
            function2(j);
}