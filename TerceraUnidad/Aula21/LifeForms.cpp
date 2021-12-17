
/* https://open.kattis.com/problems/lifeforms
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;



constexpr int INF = 2000000010;
constexpr ll LLINF = 9000000000000000010LL;

struct SuffixArray {
	vi w;
	int n;
	vvi P;
	SuffixArray(vi &_w){ 
        w = _w;
        n = w.size();
        P.push_back(vi(n, 0)); 

        vi cnt(256, 0);
		for (int i = 0; i < n; ++i) cnt[w[i]]++;
		for (int i = 0, mp = 0; i < 256; ++i)
			if (cnt[i] > 0) cnt[i] = mp++;
		for (int i = 0; i < n; ++i) P[0][i] = cnt[w[i]];
		vi occ(n + 1, 0), s1(n, 0), s2(n, 0);
		for (int k = 1, cnt = 1; cnt / 2 < n; ++k, cnt *= 2) {
			P.push_back(vi(n, 0));
			fill(occ.begin(), occ.end(), 0);
			for (int i = 0; i < n; ++i)
				occ[i+cnt<n ? P[k-1][i+cnt]+1 : 0]++;
			partial_sum(occ.begin(), occ.end(), occ.begin());
			for (int i = n - 1; i >= 0; --i)
				s1[--occ[i+cnt<n ? P[k-1][i+cnt]+1 : 0]] = i;
			fill(occ.begin(), occ.end(), 0);
			for (int i = 0; i < n; ++i)
				occ[P[k-1][s1[i]]]++;
			partial_sum(occ.begin(), occ.end(), occ.begin());
			for (int i = n - 1; i >= 0; --i)
				s2[--occ[P[k-1][s1[i]]]] = s1[i];
			for (int i = 1; i < n; ++i) {
				P[k][s2[i]] = same(s2[i], s2[i - 1], k, cnt) 
					? P[k][s2[i - 1]] : i;
			}
		}
    }

	bool same(int i, int j, int k, int l) {
		return P[k - 1][i] == P[k - 1][j]
			&& (i + l < n ? P[k - 1][i + l] : -1)
			== (j + l < n ? P[k - 1][j + l] : -1);
	}
	const vi &get_array() { return P.back(); }
	int lcp(int x, int y) {
		int ret = 0;
		if (x == y) return n - x;
		for (int k = P.size() - 1; k >= 0 && x < n && y < n; --k)
			if (P[k][x] == P[k][y]) {
				x += 1 << k;
				y += 1 << k;
				ret += 1 << k;
			}
		return ret;
	}
};

int main() {

	int n;
	bool e = false;
	while (cin >> n) {
		if (n == 0) break;

		if (e) cout << '\n'; else e = true;

		if (n == 1) {
			string s;
			cin >> s;
			cout << s << "\n";
			continue;
		}

		vi word, owner;
		int ntok = 26;
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			for (char c : s)
				word.push_back(c-'a');
			word.push_back(ntok++);
			owner.push_back((int)word.size());
		}

		int S = (int)word.size();

		SuffixArray sa(word);
		const vi &p = sa.get_array();
		vi pi(S), po(S);
		for (int i = 0, o = 0; i < (int)word.size(); ++i) {
			if (owner[o] <= i) ++o;
			pi[p[i]] = i;
			po[p[i]] = o;
		}

		vi ans, have(n, 0);
		int len = 0, havet = 0;
		for (int l = 0, r = 0; r < S; ++r) {
			if (!have[po[r]])
				++havet;
			++have[po[r]];
			
			while (l < r && (have[po[l]] > 1 || (havet - 1) > n/2)) {
				--have[po[l]];
				if (have[po[l]] == 0) --havet;
				l++;
			}
			if (havet <= n/2) continue;
			int tlen = sa.lcp(pi[l], pi[r]);
			if (tlen > len)
				len = tlen,
				ans.clear();
			if (tlen == len && (ans.size() == 0 || 
				(sa.lcp(pi[l], ans.back()) < len)
					))
				ans.push_back(pi[l]);
		}

		if (len == 0)
			cout << "?\n";
		else {
			for (int i : ans) {
				for (int j = i; j < i+len; ++j)
					cout << char('a'+word[j]);
				cout << '\n';
			}
		}
	}

	cout << flush;
	return 0;
}