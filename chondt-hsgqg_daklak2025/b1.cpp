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
#define Name "b1"

vector<int>primes = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47 };

vll nums;

void Try(int idx, int mx, ll a, uint64_t num, ll cnt) {
	if (idx == primes.size()) {
		nums.pb({ cnt, -num });
		return;
	}
	nums.pb({ cnt, -num });
	FOR(i, 1, mx) {
		if (num > a / primes[idx])break;
		num *= primes[idx];
		Try(idx + 1, i, a, num, cnt * (i + 1));
	}
}

pll f[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	Try(0, 64, 1e18, 1, 1);
	sort(all(nums), [&](pll x, pll y) {
		return x.Y > y.Y;
		});

	vl pos;

	f[0] = { 1, -1 };
	FOR(i, 1, nums.size()) {
		f[i] = max(f[i - 1], nums[i - 1]);
		pos.push_back(-nums[i - 1].Y);
	}

	ll n, a;
	cin >> n;
	while (n--) {
		cin >> a;
		pll res = f[upper_bound(all(pos), a) - pos.begin()];
		cout << -res.Y << ' ' << res.X << endl;
	}
}