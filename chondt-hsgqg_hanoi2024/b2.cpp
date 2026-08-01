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
#define Name "b2"

int n;
string s;
int g[30];

int f() {
	unordered_set<int >st;
	FOR(i, 1, n)st.insert(s[i]);
	return st.size();
}

struct Counter {
	int fre[30];
	int cnt = 0;

	void add(int x) {
		x -= 'a';
		if (fre[x] == 0)cnt++;
		fre[x]++;
	}

	void rem(int x) {
		x -= 'a';
		if (fre[x] == 1)cnt--;
		fre[x]--;
	}

	void clear() {
		memset(fre, 0, sizeof fre);
		cnt = 0;
	}
}c1, c2;

ll calc(int k) {
	c1.clear();
	c2.clear();

	int l = 1, r = 1, l2 = 1;
	ll res = 0;
	while (r <= n) {
		c1.add(s[r]);
		c2.add(s[r]);

		while (c1.cnt >= k) {
			c1.rem(s[l]);
			l++;
			if (c1.cnt < k) {
				c1.add(s[--l]);
				break;
			}
		}

		while (c2.cnt > k) {
			c2.rem(s[l2++]);
		}

		if (c1.cnt >= k)
			res += l - l2 + 1;

		r++;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> s;
	n = s.size();
	s = "_" + s;

	FOR(i, 1, f()) {
		cout << calc(i) << endl;
	}
}
