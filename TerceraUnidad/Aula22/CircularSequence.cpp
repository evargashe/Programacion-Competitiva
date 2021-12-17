/* 
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=4459
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--){
		string secuencia; cin >> secuencia;
		int tam = secuencia.size();
		vector<string> vec;
		vec.push_back(secuencia);
		for(int i=1;i<tam;i++){
			string first = secuencia.substr(i);
			string second = secuencia.substr(0,i);
			vec.push_back(first+second);
		}
		sort(vec.begin(),vec.end());
		cout << vec[0] << endl;
	}
	return 0;
}