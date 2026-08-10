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
#define Name "PALINPRIME"

mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());

bool p[155];

bool ok(ll a) {
	ll s = 0;
	while (a != 0) {
		s += a % 10;
		a /= 10;
	}
	return p[s];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 150; i++)if (p[i])for (int j = i * i; j <= 150; j += i)p[j] = 0;

	ll l, r, res = 0;
	cin >> l >> r;

	FOR(i, 1, 1e6) {
		ll a = i, b = i, t = i;
		b = b * 10 + t % 10;
		t /= 10;
		while (t != 0) {
			a = a * 10 + (t % 10);
			b = b * 10 + (t % 10);
			t /= 10;
		}
		if (ok(a) && l <= a && a <= r)res++;
		if (ok(b) && l <= b && b <= r)res++;
	}

	cout << res << endl;
}