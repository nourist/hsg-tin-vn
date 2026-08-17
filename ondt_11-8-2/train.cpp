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
#define Name "train"

int n, m, d;
struct Order {
	int s, t, v;
}a[30];

int suffix[30];
int res = 0;
int cap[30];

void Try(int idx, int cur) {
	if (idx == d + 1) {
		res = max(res, cur);
		return;
	}

	if (cur + suffix[idx] < res)return;

	bool ok = 1;
	FOR(i, a[idx].s, a[idx].t - 1) {
		if (cap[i] + a[idx].v > n) {
			ok = 0;
		}
	}

	if (ok) {
		FOR(i, a[idx].s, a[idx].t - 1) {
			cap[i] += a[idx].v;
		}

		Try(idx + 1, cur + a[idx].v * (a[idx].t - a[idx].s));

		FOR(i, a[idx].s, a[idx].t - 1) {
			cap[i] -= a[idx].v;
		}
	}

	Try(idx + 1, cur);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> m >> d;

	FOR(i, 1, d) {
		cin >> a[i].s >> a[i].t >> a[i].v;
	}

	FOD(i, d, 1) {
		suffix[i] = suffix[i + 1] + a[i].v * (a[i].t - a[i].s);
	}

	Try(1, 0);

	cout << res;
}
