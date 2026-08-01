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
#define Name "b6"

int x[(int)3e5 + 5];
int p[(int)3e5 + 5];
priority_queue<pll, vll, greater<pll>>f[(int)3e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	ll n, s;
	cin >> n >> s;
	FOR(i, 1, n)cin >> x[i] >> p[i];

	FOD(i, n, 1) {
		ll req = max(0, -x[i]);
		ll gain = x[i];

		while (!f[i].empty()) {
			auto t = f[i].top();

			if (gain <= 0 || t.X <= req) {
				f[i].pop();
				req = max(req, t.X - gain);
				gain += t.Y;
			}
			else {
				break;
			}
		}

		if (gain > 0)f[i].push({ req, gain });

		if (f[p[i]].size() < f[i].size()) {
			swap(f[p[i]], f[i]);
		}
		while (!f[i].empty()) {
			f[p[i]].push(f[i].top());
			f[i].pop();
		}
	}

	ll oldS = s;

	while (!f[0].empty()) {
		auto t = f[0].top();
		f[0].pop();

		if (t.X <= s) {
			s += t.Y;
		}
	}
	cout << s - oldS;
}
