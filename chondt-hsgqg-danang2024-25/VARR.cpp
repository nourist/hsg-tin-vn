#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); i++)
#define FOD(i,r,l) for (int i = (r); i >= (l); i--)
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
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "varr"

int n;
int a[(int)2e5 + 5];
int f[(int)2e5 + 5];
ll cnt[21];
int freq[(int)1e6 + 6];

ll solve(int x) {
	memset(freq, 0, sizeof freq);

	freq[0] = 1;

	ll res = 0;

	FOR(i, 1, n) {
		res += freq[f[i] % x]++;
	}

	return res;
}

const int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)f[i] = f[i - 1] + a[i];

	FOR(i, 0, 19)cnt[i] = solve(1 << i);

	ll res = 0;
	FOR(i, 0, 19)res += (cnt[i] - cnt[i + 1]) % mod * (1 << i) % mod;
	// FOR(i, 0, 19)cout << cnt[i] << ' ';
	// cout << endl;
	cout << res % mod;
}
