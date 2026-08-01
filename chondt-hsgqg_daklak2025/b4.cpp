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
#define Name "b4"

int n;
const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;
int a[(int)1e5 + 5];
ll base1[(int)1e5 + 5];
ll f1[(int)1e5 + 5];
ll base2[(int)1e5 + 5];
ll f2[(int)1e5 + 5];

ll getValue1(int l, int r) {
	return (f1[r] - f1[l - 1] * base1[r - l + 1] % mod1 + mod1) % mod1;
}
ll getValue2(int l, int r) {
	return (f2[r] - f2[l - 1] * base2[r - l + 1] % mod2 + mod2) % mod2;
}

int ok(int mid, int mx) {
	unordered_map<ll, int>mp1;

	FOR(r, mid, n) {
		mp1[getValue1(r - mid + 1, r) * ((int)1e9 + 21) + getValue2(r - mid + 1, r)]++;
	}

	int res = -1;
	FOR(r, mid, n) {
		if (mp1[getValue1(r - mid + 1, r) * ((int)1e9 + 21) + getValue2(r - mid + 1, r)] == mx)res = r - mid + 1;
	}
	return res;
}

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

	unordered_map<int, int>mp;
	FOR(i, 1, n)mp[a[i]]++;

	int mx = 0;
	for (auto it : mp) mx = max(mx, it.Y);

	int cnt = 1;
	for (auto it = mp.begin(); it != mp.end(); it++)it->Y = cnt++;

	FOR(i, 1, n)a[i] = mp[a[i]];

	base1[0] = 1;
	FOR(i, 1, n)base1[i] = base1[i - 1] * ((ll)1e5 + 5) % mod1;
	FOR(i, 1, n) f1[i] = (f1[i - 1] * ((ll)1e5 + 5) % mod1 + a[i] + 1) % mod1;

	base2[0] = 1;
	FOR(i, 1, n)base2[i] = base2[i - 1] * ((ll)1e5 + 5) % mod2;
	FOR(i, 1, n) f2[i] = (f2[i - 1] * ((ll)1e5 + 5) % mod2 + a[i] + 1) % mod2;

	pii res;
	int l = 1, r = n;
	while (l <= r) {
		int mid = l + r >> 1;
		int tmp = ok(mid, mx);
		if (tmp != -1) {
			res = { tmp, tmp + mid - 1 };
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << res.X << ' ' << res.Y;
}
