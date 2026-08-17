#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); ++i)
#define FOD(i,r,l) for (int i = (r); i >= (l); --i)
#define ll long long
#define db double
#define L first
#define W second
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
#define Name "khobau"

pii a[(int)5e4 + 4];
ll dp[(int)5e4 + 4];

struct Segment {
	double x;
	ll a, b, id;

	Segment(double _x = 0, ll _a = 0, ll _b = 0, ll _id = 0) : x(_x), a(_a), b(_b), id(_id) {};

	ll y(ll x) {
		return 1LL * a * x + b;
	}
};

bool operator < (Segment x, Segment y) {
	return x.x < y.x;
}

struct Hull {
	vector<Segment>st;

	void add(ll a, ll b, ll id) {
		while (st.size() >= 1) {
			double X = st.back().x;
			ll A = st.back().a;
			ll B = st.back().b;

			if (X * A + B >= X * a + b) {
				st.pop_back();
			}
			else {
				break;
			}
		}

		if (st.empty()) {
			st.push_back({ -1e9, a, b, id });
			return;
		}

		ll A = st.back().a;
		ll B = st.back().b;

		if (A == a)return;

		double inter = 1.0 * (B - b) / (a - A);

		st.push_back({ inter, a, b, id });
	}

	void rem(ll id) {
		if (!st.empty() && st.back().id == id)st.pop_back();
	}

	ll query(ll t) {
		ll it = upper_bound(all(st), Segment(t)) - st.begin() - 1;
		return st[it].y(t);
	}
}hull;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i].L >> a[i].W;

	sort(a + 1, a + n + 1);

	vector<pii> b;
	b.push_back({ 0, 0 }); // padding để dùng index từ 1

	FOR(i, 1, n) {
		while (b.size() > 1 && b.back().W <= a[i].W) {
			b.pop_back();
		}
		b.push_back(a[i]);
	}

	int m = b.size() - 1;
	vector<ll> dp(m + 1, 0);

	hull.st.clear();

	hull.add(b[1].W, dp[0], 0);

	FOR(i, 1, m) {
		dp[i] = hull.query(b[i].L);
		if (i < m) {
			hull.add(b[i + 1].W, dp[i], i);
		}
	}

	cout << dp[m];
}
