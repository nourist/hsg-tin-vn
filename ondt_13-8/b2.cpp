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
string a, b;

pii nxt(pii u) {
	while (u.X <= n && a[u.X] == b[u.X])u.X++;
	while (u.Y >= 1 && a[u.Y] == b[u.Y])u.Y--;
	return u;
}

void Try(int idx, int l, int r) {
	if (l > r) {
		cout << "Similar";
		exit(0);
	}
	if (idx == 5) {
		return;
	}

	FOR(i, l, r) {
		if (a[i] == b[l]) {
			reverse(a.begin() + l, a.begin() + i + 1);
			pii pos = nxt({ l,r });
			Try(idx + 1, pos.X, pos.Y);
			reverse(a.begin() + l, a.begin() + i + 1);
		}

		if (a[i] == b[r]) {
			reverse(a.begin() + i, a.begin() + r + 1);
			pii pos = nxt({ l,r });
			Try(idx + 1, pos.X, pos.Y);
			reverse(a.begin() + i, a.begin() + r + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> a >> b;

	n = a.size();
	a = "_" + a;
	b = "_" + b;

	pii pos = nxt({ 1, n });

	Try(1, pos.X, pos.Y);
	cout << "Different";
}
