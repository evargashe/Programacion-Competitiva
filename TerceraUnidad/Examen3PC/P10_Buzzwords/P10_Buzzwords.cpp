/* 
https://open.kattis.com/problems/buzzwords
 */

#include <bits/stdc++.h>
using namespace std;

class nodo{
private:
	nodo*	ch[26];
	int 	c=0;
	int 	d=0;
public:
	nodo(){
		for(int i = 0; i < 26; ++i) 
			ch[i] = NULL;
	}
	void insertar(string &s, int i = 0){
		while(i<s.length() && s[i]==' ') 
			i++;
		if(i==s.length()){ 
			c++; 
			return; 
		}
		else{
			c++;
			int v=s[i]-'A';
			if(ch[v] == NULL){
				ch[v] = new nodo();
				ch[v]->d=d+1;
			}
			ch[v]->insertar(s,i+1);
		}
	}
	void limpiar(){
		for(int i=0;i<26;++i){
			if (ch[i] != NULL) 
				ch[i]->limpiar();
			delete ch[i];
		}
	}
	void count(vector<int>&count){
		count[d]=max(c, count[d]);
		for (int i=0;i<26;++i)
			if (ch[i]!=NULL)
				ch[i]->count(count);
	}
};



int main(){
    string S;
	while(getline(cin,S)){
        nodo root;
        for(int i = 0;i<S.length();++i){
            if(S[i]!=' ')
                root.insertar(S, i);
        }

        vector<int> dpth(S.length()+3,0);
        root.count(dpth);
        for(int i=1;i<=S.length()+1;++i){
            if(dpth[i]>1) 
                cout<<dpth[i]<<"\n";
        }     
            cout<<"\n";
        }
	
	return 0;
}