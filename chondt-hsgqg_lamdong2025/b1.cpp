#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); ++i)
#define FOD(i,r,l) for (int i = (r); i >= (l); --i)
#define ll long long
#define db double
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define endl '\n'
#define BIT(x, i) (((x) >> (i)) & 1)
#define BIT_COUNT(x) __builtin_popcountll(x)
#define LOWEST_BIT(x) __builtin_ctzll(x)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "b1"

string p, s;

const ll mod1 = 1e9 + 7, mod2 = 1e9 + 9;
ll base1[(int)6e6 + 6];
ll base2[(int)6e6 + 6];
ll f1[(int)6e6 + 6];
ll f2[(int)6e6 + 6];

int match(int l, int r, int u, int v) {
	if (r - l != v - u)return 0;
	return (f1[r] - f1[l - 1] * base1[r - l + 1] % mod1 + mod1) % mod1 == (f1[v] - f1[u - 1] * base1[v - u + 1] % mod1 + mod1) % mod1 &&
		(f2[r] - f2[l - 1] * base2[r - l + 1] % mod2 + mod2) % mod2 == (f2[v] - f2[u - 1] * base2[v - u + 1] % mod2 + mod2) % mod2;
}

bool ok(int l0, int l1) {
	int s0, s1, sum = 0;
	FOR(i, 0, p.size() - 1) {
		if (p[i] == '0') {
			s0 = sum + 1;
			sum += l0;
		}
		else {
			s1 = sum + 1;
			sum += l1;
		}
	}
	if (match(s0, s0 + l0 - 1, s1, s1 + l1 - 1))return 0;
	sum = 0;
	FOR(i, 0, p.size() - 1) {
		if (p[i] == '0') {
			if (!match(s0, s0 + l0 - 1, sum + 1, sum + l0))return 0;
			sum += l0;
		}
		else {
			if (!match(s1, s1 + l1 - 1, sum + 1, sum + l1))return 0;
			sum += l1;
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	base1[0] = base2[0] = 1;
	FOR(i, 1, 5e6) {
		base1[i] = base1[i - 1] * 27 % mod1;
		base2[i] = base2[i - 1] * 27 % mod2;
	}

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int t;
	cin >> t;
	while (t--) {
		cin >> p >> s;

		FOR(i, 1, s.size()) {
			f1[i] = (f1[i - 1] * 27 + s[i - 1] - 'a' + 1) % mod1;
			f2[i] = (f2[i - 1] * 27 + s[i - 1] - 'a' + 1) % mod2;
		}

		int c0 = 0, c1 = 0;
		for (int i : p) {
			if (i == '0') c0++;
			else c1++;
		}

		int res = 0;
		FOR(l1, 1, (int)s.size() - 1) {
			if ((s.size() - 1LL * l1 * c0) % c1 == 0) {
				ll l2 = (s.size() - 1LL * l1 * c0) / c1;
				if (l2 <= 0)continue;
				// cout << l1 << ' ' << l2 << endl;
				res += ok(l1, l2);
				// if (ok(l1, l2))cout << "OK" << endl;
			}
		}
		cout << res << endl;
	}
}
