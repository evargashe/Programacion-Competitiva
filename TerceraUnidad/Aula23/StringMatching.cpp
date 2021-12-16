
/* https://open.kattis.com/problems/stringmatching
 */
#include <bits/stdc++.h>

using namespace std;


int main() {
    
    int x,y,z;
    string sub, full;
    while (getline(cin,sub)) {
        getline(cin,full);

        vector<int> tab(sub.size() + 1, -1);
        for(int i = 1; i <= sub.size(); i++)
        {
            int pos = tab[i - 1];
            
            while(pos != -1 && sub[pos] != sub[i - 1]){
                pos = tab[pos];
            }
            tab[i] = pos + 1;
        }
        
        int fullIndex = 0;
        int subIndex = 0;
        
        int fSize = (int)full.size();
        int sSize = (int)sub.size();
        
        while(fullIndex < fSize)
        {
            while(subIndex != -1 && (subIndex == sSize || sub[subIndex] != full[fullIndex]))
                subIndex = tab[subIndex];
            
            subIndex++;
            fullIndex++;
            
            if(subIndex == sSize){
                cout << fullIndex - sSize << " ";
            }
        }
        cout << "\n";

    }
    return 0;   
}