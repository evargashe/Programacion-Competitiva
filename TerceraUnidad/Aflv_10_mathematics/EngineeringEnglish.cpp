#include <bits/stdc++.h>
#include <cctype>
using namespace std;


string aMinuscula(string cadena) {
  for (int i = 0; i < cadena.length(); i++) cadena[i] = tolower(cadena[i]);
  return cadena;
}
int main() {
    string s;
    int i=0;

    cin>>s;
    vector<string> aux;
    string b;
    cout<<s.size();
    /* for(int i=0; i<s.size(); )
    {
        if(s[i]!=' ')
        {
            b+=s[i];
        }
        else{
            aux.push_back(b);
            b.clear();
        }
        
    }

    for(int i=0; i<aux.size(); i++)
    {
        cout<<aux[i]<<" ";
    } */

    
    /* 
    vector<string> v;
    vector<string>::iterator iter=v.begin();
    while(cin>>s)
    {
        if(i==0){
            v.push_back(aMinuscula(s));
            cout<<s<<" ";
        }
        else
        {
            iter=find(v.begin(),v.end(),aMinuscula(s));
            if(iter!=v.end())
            {
                if(i==1){
                    cout<<".";
                }else{
                    cout<<" .";
                }
            }
            else
            {
                if(i==1){
                    cout<<s;
                }else{
                    cout<<" "<<s;
                }
                v.push_back(aMinuscula(s));
            }
        }
        i++;
    } */
    return 0;
}