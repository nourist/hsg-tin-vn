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
#define Name "b4"

mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());

uint64_t id[(int)2e5 + 5];
uint64_t a[(int)2e5 + 5];
uint64_t b[(int)2e5 + 5];
uint64_t d[(int)2e5 + 5];
uint64_t fa[(int)2e5 + 5];
uint64_t fb[(int)2e5 + 5];
uint64_t fd[(int)2e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}
	FOR(i, 1, 2e5)id[i] = Rand();

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		FOR(i, 1, n)cin >> a[i];
		FOR(i, 1, n)cin >> b[i];
		FOR(i, 1, n)a[i] = id[a[i]];
		FOR(i, 1, n)b[i] = id[b[i]];
		FOR(i, 1, n)d[i] = b[i] - a[i];
		FOR(i, 1, n)fa[i] = fa[i - 1] + a[i];
		FOR(i, 1, n)fb[i] = fb[i - 1] + b[i];
		FOR(i, 1, n)fd[i] = fd[i - 1] + d[i];

		uint64_t S = 0;
		FOR(i, 1, n)S += id[i];

		ll res = 0;
		unordered_map<uint64_t, int>mp;
		mp[0] = 1;
		FOR(i, 1, n) {
			res += mp[-(S - fa[n] - fd[i])];
			if (S - fb[n] + fd[i] != -(S - fa[n] - fd[i]))
				res += mp[S - fb[n] + fd[i]];
			mp[fd[i]]++;
		}

		cout << res << endl;
	}
}

/*
sumD = sumA - sumB
fd[j] - fd[i-1] = S - sumA
- (sumD[j] - sumD[i-1]) = S - sumB
*/
