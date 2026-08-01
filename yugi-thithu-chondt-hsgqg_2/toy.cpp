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
#define Name "toy"

pii a[(int)1e5 + 5];
bool used[(int)1e5 + 5];

void solve() {
	int n, k;
	vii v;

	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> a[i].X >> a[i].Y;
		v.pb({ i, 1 });
		v.pb({ i, 2 });
	}

	memset(used, 0, sizeof used);

	sort(all(v), [&](pii u, pii v) {
		int vu = u.Y == 1 ? a[u.X].X : a[u.X].Y;
		int vv = v.Y == 1 ? a[v.X].X : a[v.X].Y;
		return vu > vv;
		});
	ll sum = 0;
	ll res = 0;
	FOR(i, 0, n * 2 - 1) {
		if (v[i].Y == 1) {
			sum += a[v[i].X].X;
			res = max(res, sum);
			k--;
			used[v[i].X] = 1;
		}
		else {
			if (used[v[i].X])res = max(res, sum + 1LL * k * a[v[i].X].Y);
			else res = max(res, sum + 1LL * (k - 1) * a[v[i].X].Y + a[v[i].X].X);
		}
		if (k == 0)break;
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int t;
	cin >> t;
	while (t--)solve();
}
