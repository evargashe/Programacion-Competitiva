/* https://open.kattis.com/problems/trendingtopic
 */
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<string,int> p1, pair<string,int> p2) {
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}


int main() {
    string s;
    vector<vector<string>> dias;
    map<int,vector<int>> consultas;

    int contdias = 0;
    dias.push_back({});

    while(cin >> s) {
        if(s == "<text>") {
            dias.push_back({});
            contdias++;
            continue;
        }
        if(s == "</text>") {
            continue;
        }
        if(s == "<top") {
            int n;
            cin >> n;
            string g;
            cin >> g;
            consultas[contdias].push_back(n);
            continue;
        }
        if(s.size() < 4) {
            continue;
        }
        dias[contdias].push_back(s);
    }
    dias.push_back({});
    contdias++;

    map<string,int> cnt;

    for(int i = 0; i < contdias; i++) {
        for(auto j : dias[i]) {
            cnt[j]++;
        }
        if(i >= 7) {
            for(auto j : dias[i-7]) {
                cnt[j]--;
                if(cnt[j] == 0) {
                    cnt.erase(j);
                }
            }
        }
        for(auto j : consultas[i]) {
            cout << "<top " << j << ">" << endl;
            map<int,vector<string>> rev;
            for(auto i : cnt) {
                rev[i.second].push_back(i.first);
            }

            auto it = prev(rev.end());

            vector<pair<string,int>> res;
            while(res.size() < j) {
                for(auto j : it->second) {
                    res.push_back({j,it->first});
                }
                if(it == rev.begin()) break;
                it--;
            }

            sort(res.begin(),res.end(),cmp);
            for(auto i : res) {
                cout << i.first << " " << i.second << endl;
            }
            cout << "</top>" << endl;
        }
    }
}