#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (int)(l); i <= (int)(r); i++)
#define FOD(i,r,l) for (int i = (int)(r); i >= (int)(l); i--)
#define ll long long
#define db double
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pib pair<int,bool>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define vib vector<pib>
#define BIT(x, i) (((x) >> (i)) & 1)
#define MARK(x, i) ((x) | (1LL << (i)))
#define UNMARK(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "twoprefixs"

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
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	string s, t;
	cin >> s >> t;

	vi pi_t = prefix_function(t);

	vector<int> f(t.size() + 2, 0);

	FOR(i, 0, t.size() - 1) {
		if (pi_t[i]) {
			int j = i - pi_t[i] + 1;
			f[j]++;
		}
	}

	FOR(i, 1, t.size())f[i] += f[i - 1];

	string e = t + "#" + s;

	vi z_e = z_function(e);

	ll res = (ll)s.size() * t.size();

	FOR(i, 0, s.size() - 2) {
		int idx = i + t.size() + 2;

		if (z_e[idx])
			res -= f[z_e[idx]];
	}

	cout << res;
}
