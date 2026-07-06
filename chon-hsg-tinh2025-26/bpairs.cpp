#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int n, a[(int)3e5 + 5];

int sumDigits(int x) {
	int s = 0;
	while (x) {
		s += x % 10;
		x /= 10;
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bpairs.inp", "r")) {
		freopen("bpairs.inp", "r", stdin);
		freopen("bpairs.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) a[i] = sumDigits(a[i]);

	unordered_map<int, int> mp;
	ll res = 0;
	FOR(i, 1, n) {
		res += mp[a[i]]++;
	}
	cout << res;
}
