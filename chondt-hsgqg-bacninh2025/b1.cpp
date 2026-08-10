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

mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());

ll n, q, a[(int)1e5 + 5];
int p[(int)1e5 + 5];
ll hashCode[(int)1e5 + 5];
ll f[(int)1e5 + 5];

ll factor(ll x) {
	ll res = 0;
	while (x != 1) {
		int cur = p[x];
		int cnt = 0;
		while (x % cur == 0) {
			x /= cur;
			cnt++;
		}
		if (cnt % 2 == 1)res ^= hashCode[cur];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	FOR(i, 1, 1e5)p[i] = i;
	for (int i = 2; i * i <= 1e5; i++)if (p[i] == i)for (int j = i * i; j <= 1e5; j += i)if (p[j] == j)p[j] = i;

	FOR(i, 1, 1e5)hashCode[i] = Rand();

	cin >> n >> q;
	FOR(i, 1, n) {
		cin >> a[i];
		f[i] = f[i - 1] ^ factor(a[i]);
	}

	while (q--) {
		int u, v;
		cin >> u >> v;
		if ((f[v] ^ f[u - 1]) == 0)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}