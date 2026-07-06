#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define Name "twoprefixs"

// Z-function chuẩn
vector<int> z_function(string s) {
	int n = s.size();
	vector<int> z(n, 0);
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	return z;
}

// KMP Prefix Function chuẩn
vector<int> prefix_function(string s) {
	int n = s.size();
	vector<int> pi(n, 0);
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	string s, t;
	if (!(cin >> s >> t)) return 0;

	int n = s.size();
	int m = t.size();

	// 1. Tính mảng pi cho t
	vector<int> pi = prefix_function(t);

	// 2. Tính min_k cho từng chiều dài j và đếm cộng dồn
	vector<int> pref(m + 2, 0);
	for (int j = 1; j <= m; j++) {
		int border_len = pi[j - 1];
		if (border_len > 0) { // Phải có border > 0 để tiền tố còn lại khác rỗng
			int min_k = j - border_len;
			if (min_k <= m) pref[min_k]++;
		}
	}

	for (int x = 1; x <= m; x++) {
		pref[x] += pref[x - 1];
	}

	// 3. Tính Z-function để tìm max match_len của phần s
	string e = t + "#" + s;
	vector<int> z_e = z_function(e);

	ll total_pairs = (ll)n * m;
	ll duplicates = 0;

	for (int i = 0; i < n - 1; i++) {
		int idx_in_e = m + 1 + (i + 1);
		int match_len = z_e[idx_in_e];

		cout << match_len << endl;

		if (match_len > 0) {
			match_len = min(match_len, m);
			duplicates += pref[match_len];
		}
	}

	cout << total_pairs - duplicates;
	return 0;
}