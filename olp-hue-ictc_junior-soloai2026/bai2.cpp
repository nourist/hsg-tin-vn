#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[(int)1e6 + 6];
int p[(int)1e6 + 6];
ll randomHashCode[(int)1e6 + 6];
ll hashCode[(int)1e6 + 6];

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	FOR(i, 1, 1e6)p[i] = i;
	for (int i = 2; i * i <= 1e6; i++) {
		if (p[i] == i) {
			for (int j = i * i; j <= 1e6; j += i) {
				if (p[j] == j) {
					p[j] = i;
				}
			}
		}
	}

	FOR(i, 1, 1e6) randomHashCode[i] = rng();

	FOR(i, 1, n) {
		while (a[i] != 1) {
			int cnt = 0;
			int t = p[a[i]];
			while (a[i] % t == 0) {
				cnt++;
				a[i] /= t;
			}

			if (cnt % 2 == 1) {
				hashCode[i] ^= randomHashCode[t];
			}
		}
	}

	unordered_map<ll, int>mp;
	ll res = 0;
	FOR(i, 1, n) {
		res += mp[hashCode[i]];
		mp[hashCode[i]]++;
	}

	cout << res;
}

/*
bcnn(a,b)/ucln(a,b) = n^2
bcnn(a,b)*ucln(a,n)=n^2*ucln(a,b)^2
a*b = n^2*ucln(a,b)^2
*/