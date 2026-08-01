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
#define Name "ENERGY"

int n;
int v[(int)1e7 + 7];
int l[(int)1e7 + 7];
int r[(int)1e7 + 7];
int bucketST[(int)1e7 + 7];
int bucketEN[(int)1e7 + 7];
int nxt[(int)1e7 + 7];

void add(int v, int i) {
	if (bucketST[v] == 0) {
		bucketST[v] = bucketEN[v] = i;
	}
	else {
		nxt[bucketEN[v]] = i;
		bucketEN[v] = i;
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

	cin >> n;
	FOR(i, 1, n)cin >> v[i];

	FOR(i, 1, n)add(v[i], i);

	FOR(i, 1, n) {
		r[i] = i + 1;
		l[i] = i - 1;
	}

	int res = 1e9;
	int mx = 1;
	FOR(i, 0, n) {
		if (bucketST[i] == 0)continue;
		for (int pos = bucketST[i]; pos != 0; pos = nxt[pos]) {
			int u = l[pos], v = r[pos];

			if (i >= mx)res = min(res, mx);

			mx = max(mx, v - u);

			r[u] = v;
			l[v] = u;
		}
	}
	cout << (res == 1e9 ? 0 : res);
}