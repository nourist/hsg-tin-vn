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
#define Name "shop"

int n;
int mapId[(int)1e6 + 6];
int d[10];
int p[10];
ll dp[(int)1e4 + 4];

int encode(const vi& keys) {
	int res = 0;
	int state = 1;
	for (auto it : keys) { res += state * it; state *= 6; }
	return res;
}

vi decode(int id) {
	vi res;
	FOR(i, 1, n) {
		res.pb(id % 6);
		id /= 6;
	}
	return res;
}

bool ok(const vi& keys) {
	for (auto it : keys)if (it > 5)return 0;
	return 1;
}

struct Combo {
	int k, p;
	vii items;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	vector<Combo>v;

	cin >> n;
	FOR(i, 1, n) {
		int c;
		cin >> c >> d[i] >> p[i];
		mapId[c] = i - 1;
		v.pb({ 1, p[i], {{i - 1, 1}} });
	}

	int limit = 1;
	FOR(i, 1, n)limit *= 6;
	FOR(i, 0, limit)dp[i] = 1e18;
	dp[encode(vi(n, 0))] = 0;

	int s;
	cin >> s;
	FOR(i, 1, s) {
		int k, p;
		cin >> k;
		vii items;
		FOR(i, 1, k) {
			int c, r;
			cin >> c >> r;
			items.pb({ mapId[c], r });
		}
		cin >> p;
		v.pb({ k, p, items });
	}

	for (auto it : v) {
		FOR(id, 0, limit) {
			vi keys = decode(id);
			for (auto i : it.items) {
				keys[i.X] += i.Y;
			}
			if (!ok(keys)) {
				continue;
			}
			int newId = encode(keys);
			dp[newId] = min(dp[newId], dp[id] + it.p);
		}
	}
	vi keys;
	FOR(i, 1, n)keys.pb(d[i]);
	cout << dp[encode(keys)];
}
