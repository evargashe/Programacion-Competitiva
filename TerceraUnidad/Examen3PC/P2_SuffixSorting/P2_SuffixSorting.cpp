/* 
https://open.kattis.com/problems/suffixsorting
 */

#include <bits/stdc++.h>
using namespace std;


char s[200000];

class SuffixArray {
   private:
    vector<int> RA;  

    void countingSort(int k) {               
        int maximo = max(300, n);             
        vector<int> c(maximo, 0);                       
        for (int i = 0; i < n; ++i)         
            ++c[i + k < n ? RA[i + k] : 0];  
        for (int i = 0, sum = 0; i < maximo; ++i) {
            int t = c[i];
            c[i] = sum;
            sum += t;
        }
        vector<int> temporal(n);
        for (int i = 0; i < n; ++i)  
            temporal[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
        swap(SA, temporal);  
    }

    void construir() {  
        SA.resize(n);
        iota(SA.begin(), SA.end(), 0); 
        RA.resize(n);
        for (int i = 0; i < n; ++i) 
            RA[i] = T[i];  
        for (int k = 1; k < n; k <<= 1) {          
            countingSort(k);  
            countingSort(0);  
            vector<int> tempRA(n);
            int r = 0;
            tempRA[SA[0]] = r;           
            for (int i = 1; i < n; ++i)  
                tempRA[SA[i]] =          
                    ((RA[SA[i]] == RA[SA[i - 1]]) 
                                    && (RA[SA[i] + k] == RA[SA[i - 1] + k])) ? r
                                                                                : ++r;
            swap(RA, tempRA);                   
            if (RA[SA[n - 1]] == n - 1) 
                break;  
        }
    }

    public:
        const char* T;  
        const int n;    
        vector<int> SA;          

        SuffixArray(const char* value, const int _n) : T(value), n(_n) {
            construir();  
        }
};



int main() {
    while (cin.getline(s, 200000)) {
        
        int n = strlen(s);
        
        s[n++] = char(9);
        SuffixArray sa(s, n);

        int num_q, q;
        cin >> num_q;
        for (int q_num = 0; q_num < num_q; q_num++) {
            cin >> q;
            if (q_num > 0) 
                cout << " ";
            cout << sa.SA[q + 1];
        }
        cout << endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        memset(s, 0, sizeof(s));
    }

    return 0;
}