/* https://cses.fi/problemset/task/2115
 */

#include <bits/stdc++.h>
using namespace std;

int funccion(string s, int K)
{
	int n = s.length();
	int res = 0;
	int countOfOne = 0;
	vector<int> freq(n+1);
	
	freq[0] = 1;
	
	for (int i = 0; i < n; i++) {
		
		countOfOne += (s[i] - '0');
		
		if (countOfOne >= K) {

			res += freq[countOfOne - K];
		}

		freq[countOfOne]++;
	}
	return res;
}

int main()
{
	string s;
    cin >> s;
    
    long int n = s.size() + 1;
    vector<long int> ans;
	while(n--){
        long int temp;
	    temp = funccion(s, n);
        ans.push_back(temp);
	}
    
    reverse(ans.begin(), ans.end());
    
    for(auto indx : ans){
        cout << indx << " ";
    }
    cout << endl;

	return 0;
}