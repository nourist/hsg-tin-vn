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
#define Name "seq"

int n, l, r;
int a[(int)2e5 + 5];
int fl[(int)2e5 + 5];
int fr[(int)2e5 + 5];

void solve() {
	memset(fl, 0, sizeof fl);
	memset(fr, 0, sizeof fr);

	FOR(i, 1, n) {
		if (i <= l)fl[a[i]]++;
		else fr[a[i]]++;
	}

	FOR(i, 1, n) {
		int d = min(fl[i], fr[i]);
		fl[i] -= d;
		fr[i] -= d;
	}

	if (l > r) {
		int k = (l - r) / 2;

		FOR(i, 1, n) {
			while (fl[i] >= 2 && k != 0) {
				k--;
				fl[i] -= 2;
			}
		}

		FOR(i, 1, n) {
			while (fl[i] >= 1 && k != 0) {
				k--;
				fl[i]--;
			}
		}

		int res = (l - r) / 2;
		FOR(i, 1, n) {
			res += fl[i];
		}
		cout << res << endl;
	}
	else {
		int k = (r - l) / 2;

		FOR(i, 1, n) {
			while (fr[i] >= 2 && k != 0) {
				k--;
				fr[i] -= 2;
			}
		}

		FOR(i, 1, n) {
			while (fr[i] >= 1 && k != 0) {
				k--;
				fr[i]--;
			}
		}

		int res = (r - l) / 2;
		FOR(i, 1, n) {
			res += fr[i];
		}
		cout << res << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> l >> r;
		FOR(i, 1, n)cin >> a[i];
		solve();
	}
}