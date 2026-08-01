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
#define Name "TRAVEL"

int d[(int)4e5 + 5];
int c[(int)4e5 + 5];
ll f[(int)4e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, l;
	cin >> n >> l;
	FOR(i, 1, n)cin >> d[i];
	FOR(i, 1, n)cin >> c[i];
	FOR(i, 1, n)d[i + n] = d[i];
	FOR(i, 1, n)c[i + n] = c[i];

	vector<pair<pii, ll>> range;

	int cnt = 0;
	FOR(i, 1, n * 2) {
		if (c[i] == 2) {
			cnt++;
		}
		else if (cnt != 0) {
			ll sum = f[]
		}
	}
}
