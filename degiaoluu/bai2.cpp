#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n;
ll a[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	unordered_map<ll, int>firstAppear, lastAppear;

	FOR(i, 1, n) {
		if (firstAppear[a[i]] == 0)firstAppear[a[i]] = i;
		lastAppear[a[i]] = i;
	}

	int res = 0;
	FOR(i, 1, n) {
		res = max(res, lastAppear[a[i]] - firstAppear[a[i]]);
	}
	FOR(i, 1, n) {
		if (lastAppear[a[i]] - firstAppear[a[i]] == res) {
			cout << a[i] << endl;
			break;
		}
	}
	cout << res << endl;
}
