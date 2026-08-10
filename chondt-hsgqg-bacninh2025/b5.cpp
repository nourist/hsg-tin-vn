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
#define Name "baomat"

int n;
string s;

int odd[(int)1e5 + 5];
int even[(int)1e5 + 5];

void manacherOdd() {
	int l = 1, r = 0;
	FOR(i, 1, n) {
		if (i <= r)odd[i] = min(r - i, odd[l + r - i]);
		while (i - odd[i] - 1 >= 1 && i + odd[i] + 1 <= n && s[i - odd[i] - 1] == s[i + odd[i] + 1]) {
			odd[i]++;
		}

		if (i + odd[i] > r) {
			r = i + odd[i];
			l = i - odd[i];
		}
	}
	FOR(i, 1, n)odd[i]++;
}

void manacherEven() {
	int l = 1, r = 0;
	FOR(i, 1, n - 1) {
		int j = i + 1;
		if (j <= r)even[i] = min(r - j + 1, even[l + r - j]);
		while (i - even[i] >= 1 && j + even[i] <= n && s[i - even[i]] == s[j + even[i]]) {
			even[i]++;
		}
		if (i + even[i] > r) {
			r = i + even[i];
			l = j - even[i];
		}
	}
}

struct WaveletTree {
	int arr[(int)1e5 + 5];
	int pref[17][(int)1e5 + 5];
	int zero[17];
	ll f[17][(int)1e5 + 5];

	void build(int* _arr) {
		FOR(i, 1, n)arr[i] = max(0, i - _arr[i]);

		FOD(k, 16, 0) {
			vi nxt0, nxt1;
			FOR(i, 1, n) {
				int bit = BIT(arr[i], k);
				pref[k][i] = pref[k][i - 1] + (!bit);
				f[k][i] = f[k][i - 1];
				if (bit) f[k][i] += arr[i];
				if (bit) nxt1.pb(arr[i]);
				else nxt0.pb(arr[i]);
			}
			zero[k] = nxt0.size();
			FOR(i, 1, nxt0.size())arr[i] = nxt0[i - 1];
			FOR(i, 1, nxt1.size())arr[i + nxt0.size()] = nxt1[i - 1];
		}
	}

	ll query(int l, int r) {
		ll x = l - 1;
		ll res = 0;
		ll sum = 1LL * (r - l + 1) * (r + l) / 2;
		FOD(i, 16, 0) {
			int cnt = pref[i][r] - pref[i][l - 1];

			int l1 = pref[i][l - 1] + 1;
			int r1 = pref[i][r];
			int l2 = l - pref[i][l - 1] + zero[i];
			int r2 = r - pref[i][r] + zero[i];

			if (BIT(x, i)) {
				res += (r1 - l1 + 1) * x;

				l = l2;
				r = r2;
			}
			else {
				res += f[i][r] - f[i][l - 1];

				l = l1;
				r = r1;
			}
		}
		if (l <= r) res += 1LL * (r - l + 1) * x;
		return sum - res;
	}
}st1, st2, st3, st4;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> s;

	n = s.size();
	s = "_" + s;

	manacherOdd();
	manacherEven();

	st1.build(odd);
	reverse(odd + 1, odd + n + 1);
	st2.build(odd);
	st3.build(even);
	reverse(even + 1, even + n);
	st4.build(even);

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;

		int mid_odd = (l + r) / 2;
		ll ans_odd = st1.query(l, mid_odd) + st2.query(n - r + 1, n - mid_odd);

		int mid_even = (l + r - 1) / 2;
		ll ans_even = st3.query(l, mid_even) + st4.query(n - r + 1, n - mid_even - 1);

		cout << ans_odd + ans_even << endl;
	}
}
