/* https://open.kattis.com/problems/suffixarrayreconstruction */


#include <bits/stdc++.h>
using namespace std;
struct Suffix {
    int posicion;
    string suffix;
};

const char PH = '#';
const char WC = '*';


inline bool insertarSuffix(string& object, Suffix& s) {
    bool wc = false;
    for (int posicionSuffix = 0, objec_pos = s.posicion;
         objec_pos < object.size();
         posicionSuffix++, objec_pos++) {

        if (s.suffix[posicionSuffix] == WC) {
            wc = true;
            break;
        }
        
        if (object[objec_pos] != PH &&
            object[objec_pos] != s.suffix[posicionSuffix])
            return false;
        else
            object[objec_pos] = s.suffix[posicionSuffix];
    }

    if (wc) {
        for (int posicionSuffix = s.suffix.size() - 1, objec_pos = object.size() - 1;
             s.suffix[posicionSuffix] != WC;
             posicionSuffix--, objec_pos--) {
            
            if (object[objec_pos] != PH &&
                object[objec_pos] != s.suffix[posicionSuffix])
                return false;
            else
                object[objec_pos] = s.suffix[posicionSuffix];
        }
    }
    
    return true;
}


string resolver(int tam, vector<Suffix>& suffixes) {
    string resultado;
    resultado.resize(tam, PH);
    
    for (Suffix& s : suffixes) {
        if (!insertarSuffix(resultado, s)) return "";
    }

    for (char c : resultado) {
        if (c == PH) return "";
    }
    
    return resultado;
}

int main() {
    int test;
    cin >> test;

    while (test--) {
        int tam, contar;
        cin >> tam >> contar;

        vector<Suffix> suffixes;
        suffixes.reserve(contar);
        
        while (contar--) {
            Suffix s;
            cin >> s.posicion >> s.suffix;
            s.posicion--; 
            suffixes.push_back(s);
        }
        
        auto resultado = resolver(tam, suffixes);
        
        if (resultado.empty()) printf("IMPOSSIBLE\n");
        else printf("%s\n", resultado.c_str());
    }
}