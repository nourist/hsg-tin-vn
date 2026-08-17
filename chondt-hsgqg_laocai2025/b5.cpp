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
#define Name "b5"

bool f[(int)1e6 + 6];
vi nums;
bool ok[] = { 1, 0, 1, 1, 0, 0 };
ll a[101][101];
ll fre[101][101];

unordered_map<ll, bool>mp;

bool check(ll u) {
	if (u <= 1e6)return f[u];

	if ((u - 1) % 2 == 0) {
		if (check(u / 2)) {
			mp[u] = 1;
			return 1;
		}
	}

	if ((u - 1) % 3 == 0) {
		if (check(u / 3)) {
			mp[u] = 1;
			return 1;
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	f[1] = 1;
	FOR(i, 1, 1e6) {
		if (!f[i])continue;
		if (i * 2 + 1 <= 1e6)f[i * 2 + 1] = 1;
		if (i * 3 + 1 <= 1e6)f[i * 3 + 1] = 1;
	}

	FOR(i, 1, 1e6)if (f[i])nums.pb(i);

	int n;
	cin >> n;
	FOR(i, 1, n)FOR(j, 1, n)a[i][j] = nums[(i - 1) * n + j - 1];

	FOR(i, 1, n)FOR(j, 1, n)fre[i][j] = a[i][j];
	FOR(i, 1, n)FOR(j, 1, n)fre[i][j] += fre[i - 1][j];
	FOR(i, 1, n)FOR(j, 1, n)fre[i][j] += fre[i][j - 1];

	FOD(l, n, 1) {
		FOR(i, l, n)FOR(j, l, n) {
			int sum = fre[i][j] - fre[i - l][j] - fre[i][j - l] + fre[i - l][j - l];
			if (check(sum)) {
				cout << l;
				return 0;
			}
		}
	}
}
