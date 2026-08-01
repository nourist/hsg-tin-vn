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
#define Name "b6"

int a[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;
	FOR(i, 1, n)cin >> a[i];

	set<pii>st;
	FOR(i, 1, n)st.insert({ a[i], i });

	while (m--) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 1) {
			st.erase({ a[u], u });
			a[u] = v;
			st.insert({ a[u], u });
		}
		else {
			if (u == v) { cout << 0 << endl; continue; }
			ll res = 1LL * a[u] * a[v];
			if (st.size() >= 3) {
				auto it = st.begin();
				while (it->Y == u || it->Y == v)it++;
				res = min(res, 1LL * (a[u] + a[v]) * it->X);
			}
			cout << res << endl;
		}
	}
}