/* https://open.kattis.com/problems/substrings
 */
#include <bits/stdc++.h>

using namespace std;


int MAX_N = 100010;
int n = -1;
string s;
vector<int> RA, SA, tempRA, tempSA, lcp;


void Fx(){
    int k = 0;
    lcp.resize(n);
    int *rank = new int[n];
    for (int i = 0; i < n; i++) 
        rank[SA[i]] = i;
    for (int i = 0; i < n; i++, k  = max(k-1, 0)){
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = SA[rank[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[rank[i]] = k;
    }
}

void countingSort(int k){
    int i, maxi = max(300, n);
    int sum = 0;
    int *c = new int[100010];
    for (i = 0; i < n; i++) 
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = 0; i < maxi; i++) { 
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (i = 0; i < n; i++) 
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    for (i = 0; i < n; i++) 
        SA[i] = tempSA[i];
}

void RepeatedSubstring(string x){
    RA.resize(MAX_N), SA.resize(MAX_N), tempRA.resize(MAX_N), tempSA.resize(MAX_N);

    s = x;
    s += '$';
    n = s.length();
    int i, k;
    for (i = 0; i < n; i++) RA[i] = s[i];
    for (i = 0; i < n; i++) SA[i] = i;
    for (k = 1; k < n; k *= 2){
        countingSort(k);
        countingSort(0);
        int r = 0;
        tempRA[SA[0]] = r;
        for (i = 1; i < n; i++){
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
        }
        for (i = 0; i < n; i++) 
            RA[i] = tempRA[i];
        if (RA[SA[n - 1]] == n - 1) 
            break;
    }   
    Fx();
}

   
int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        RepeatedSubstring(s);
        int ans = lcp[0], i;
        for(i = 1; i < n; i++){
            if (lcp[i] > lcp[i-1]){
                ans += (lcp[i] - lcp[i-1]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}