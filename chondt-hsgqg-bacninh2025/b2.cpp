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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	vii v;

	int n, t;
	cin >> n >> t;
	FOR(i, 1, t) {
		int l, r;
		cin >> l >> r;
		v.pb({ l, 1 });
		v.pb({ r + 1, -1 });
	}

	v.pb({ 1, 0 });
	v.pb({ n + 1, 0 });

	sort(all(v));

	// for (auto it : v)cout << it.X << ' ' << it.Y << endl;

	int res = 0;
	int cur = 0;
	FOR(i, 1, v.size() - 1) {
		res += (v[i].X - v[i - 1].X) * (cur % 3 == 0);
		cur += v[i].Y;
	}
	cout << res << endl;
}
