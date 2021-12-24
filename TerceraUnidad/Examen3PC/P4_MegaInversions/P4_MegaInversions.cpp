/* https://open.kattis.com/problems/megainversions
 */

#include <bits/stdc++.h>

using namespace std;
const int MX = 100000;

long long arr2[MX], arr1[MX];
int n;

void actualizarArr (int i, int val, long long ar[]) {
	for (; i <= n; i += i&(-i)) {
		ar[i] += val;
	}
}

long long consultaArr (int i, long long ar[]) {
	long long res = 0;
	for (; i; i -= i&(-i)) {
		res += ar[i];
	}
	return res;
}

int main () {
	cin >> n;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	long long sol = 0;
	for (int i = n - 1; i >= 0; i--) {
		sol += consultaArr(ar[i] - 1, arr2);
		long long uno = consultaArr(ar[i] - 1, arr1);
		actualizarArr(ar[i], 1, arr1);
		actualizarArr(ar[i], uno, arr2);
	}
	cout << sol << '\n';
}
