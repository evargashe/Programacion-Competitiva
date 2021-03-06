/* 
https://open.kattis.com/problems/burrowswheeler
 */
 
#include <bits/stdc++.h>
using namespace std;


class Wheeler {
   private:
    vector<int> RA;  

    void counting(int k) {               
        int maxi = max(300, n);              
        vector<int> c(maxi, 0);                       
        for (int i = 0; i < n; ++i)          
            ++c[i + k < n ? RA[i + k] : 0];  
        for (int i = 0, sum = 0; i < maxi; ++i) {
            int t = c[i];
            c[i] = sum;
            sum += t;
        }
        vector<int> tempSA(n);
        for (int i = 0; i < n; ++i)  
            tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
        swap(SA, tempSA);  
    }

    void constructor() {  
        SA.resize(n);
        iota(SA.begin(), SA.end(), 0);  
        RA.resize(n);
        for (int i = 0; i < n; ++i) RA[i] = T[i];  
        for (int k = 1; k < n; k <<= 1) {          
            counting(k); 
            counting(0);  
            vector<int> tempRA(n);
            int r = 0;
            tempRA[SA[0]] = r;           
            for (int i = 1; i < n; ++i)  
                tempRA[SA[i]] =         
                    ((RA[SA[i]] == RA[SA[i - 1]]) && (RA[SA[i] + k] == RA[SA[i - 1] + k])) ? r
                                                                                           : ++r;
            swap(RA, tempRA);                   
            if (RA[SA[n - 1]] == n - 1) break;  
        }
    }

    void lcp() {
        vector<int> Phi(n);
        vector<int> PLCP(n);
        PLCP.resize(n);
        Phi[SA[0]] = -1;                     
        for (int i = 1; i < n; ++i)          
            Phi[SA[i]] = SA[i - 1];           
        for (int i = 0, L = 0; i < n; ++i) {  
            if (Phi[i] == -1) {
                PLCP[i] = 0;
                continue;
            }  
            while ((i + L < n) && (Phi[i] + L < n) && (T[i + L] == T[Phi[i] + L]))
                ++L;  
            PLCP[i] = L;
            L = max(L - 1, 0);  
        }
        LCP.resize(n);
        for (int i = 0; i < n; ++i)  
            LCP[i] = PLCP[SA[i]];    
    }

   public:
    string T;     
    const int n;  
    vector<int> SA;        
    vector<int> LCP;       

    Wheeler(string inicial) : T(inicial), n(inicial.size()) {
        constructor(); 
        lcp();   
    }
};
string T;
int main() {
    while (getline(cin, T)) {
        int n = T.size();
        T += T;
        T.pop_back();  
                       
        T += char(9);  
        Wheeler SA(T);
        for (auto i : SA.SA) {
            if (i >= n) continue;
            cout << T[i + n - 1];
        }
        cout << endl;
    }

    return 0;
}