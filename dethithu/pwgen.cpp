#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

void solve1(ll n, ll a, ll b, ll c) {
	c = n - a - b;
	FOR(i, 0, c - 1)cout << (char)('0' + (i % 2));
	FOR(i, 0, a - 1)cout << (char)('A' + (i % 2));
	FOR(i, 0, b - 1)cout << (char)('a' + (i % 2));
}

void solve2(ll n, ll a, ll b, ll c) {
	b = n - a - c;
	FOR(i, 0, b - 1)cout << (char)('z' - (i % 2));
	FOR(i, 0, a - 1)cout << (char)('Z' - (i % 2));
	FOR(i, 0, c - 1)cout << (char)('9' - (i % 2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("pwgen.inp", "r")) {
		freopen("pwgen.inp", "r", stdin);
		freopen("pwgen.out", "w", stdout);
	}

	ll n, a, b, c;
	cin >> n >> a >> b >> c;
	solve1(n, a, b, c);
	cout << endl;
	solve2(n, a, b, c);
}
