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
#define Name "Energy"

mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());

int a[(int)2e5 + 5];
int p[(int)1e6 + 6];
int cnt[(int)1e6 + 6];

bool isBetter(int u, int v) {
	if (cnt[a[u]] != cnt[a[v]]) return cnt[a[u]] < cnt[a[v]];
	return u < v;
}

struct Node {
	int x = 1e9, y = 1e9;

	void add(int i) {
		if (x == 1e9) {
			x = i;
			return;
		}

		if (isBetter(i, x)) {
			y = x;
			x = i;
		}
		else if (y == 1e9 || isBetter(i, y)) {
			y = i;
		}
	}

	int get(int i) {
		if (x != i)return x;
		return y;
	}
} f[(int)1e6 + 6];

int calcCnt(int n) {
	int res = 0;
	while (n != 1) {
		res++;
		n /= p[n];
	}
	return res;
}

void calcF(int x) {
	for (int i = 1; i * i <= a[x]; i++) {
		if (a[x] % i == 0) {
			int j = a[x] / i;

			f[i].add(x);
			if (i * i != a[x])f[j].add(x);
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

	FOR(i, 1, 1e6)p[i] = i;
	for (int i = 2; i * i <= 1e6; i++)if (p[i] == i)for (int j = i * i; j <= 1e6; j += i)if (p[j] == j)p[j] = i;
	FOR(i, 1, 1e6)cnt[i] = calcCnt(i);

	int n;
	cin >> n;

	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)calcF(i);
	FOR(i, 1, n) {
		pii res = { 1e9,1e9 };
		for (int j = 1; j * j <= a[i]; j++) {
			if (a[i] % j == 0) {
				int k = a[i] / j;
				if (f[j].get(i) != 1e9)
					res = min(res, { cnt[a[i]] + cnt[a[f[j].get(i)]] - 2 * cnt[j], f[j].get(i) });
				if (f[k].get(i) != 1e9)
					res = min(res, { cnt[a[i]] + cnt[a[f[k].get(i)]] - 2 * cnt[k], f[k].get(i) });
			}
		}

		cout << res.Y << ' ' << res.X << endl;
	}
}