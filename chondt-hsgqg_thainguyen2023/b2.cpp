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

int n, l, r;
string a[(int)1e3 + 3];
string dp[(int)1e3 + 3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> l >> r;
	FOR(i, 1, n)cin >> a[i];

	int s = 0;
	FOR(i, 1, n)s += a[i].size();

	sort(a + 1, a + n + 1, [&](string x, string y) {
		return x + y > y + x;
		});

	FOR(i, 1, n) {
		FOD(j, s, a[i].size()) {
			if (j - a[i].size() == 0 || dp[j - a[i].size()].size() != 0) {
				if (dp[j].size() == 0)dp[j] = dp[j - a[i].size()] + a[i];
				dp[j] = max(dp[j], dp[j - a[i].size()] + a[i]);
			}
		}
	}

	string res = "";

	FOR(i, l, r) {
		if (dp[i].size() != 0)res = max(res, dp[i]);
	}

	if (res.size() == 0)cout << -1;
	else cout << res;
}
