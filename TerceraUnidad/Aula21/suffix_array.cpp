#include <bits/stdc++.h>
using namespace std;

vector<int> SuffixArray(string text){
    
    int n = text.size();
    map<string,int> order_id;
    
    vector<int> suffix(n);

    for (size_t i = 0; i < n; i++) {
        order_id[text.substr(i, n)] = i;
    }
    int j = 0;
    for (auto x : order_id) {
        suffix[j] = x.second;
        j++;
    }
    return suffix;

}

int main(){

    string text;
    cin >> text;
    vector<int> a = SuffixArray(text);
     
    
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }

    return 0;
}

