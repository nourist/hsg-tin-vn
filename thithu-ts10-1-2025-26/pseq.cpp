#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

ll n, s, a[(int)1e6 + 6], c[(int)1e6+6];
bool p[(int)2e5 + 5];
ll l[(int)2e5+5], r[(int)2e5+5];

void sieve() {
	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i*i <= 2e5; i++)
		if (p[i])
			for (int j = i*i; j <= 2e5; j += i)
				p[j] = 0;
	FOR(i,1,2e5) {
		if (p[i])l[i] = i;
		else l[i] = l[i-1];
	}
	FOD(i,2e5,1) {
		if (p[i])r[i] = i;
		else r[i] = r[i+1];
	}
}

void solveC() {
	FOR(i, 1, n) {
		if (l[a[i]] != 0) {
			c[i] = min(a[i] - l[a[i]], r[a[i]] - a[i]);
		}
		else {
			c[i] = r[a[i]] - a[i];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("pseq.inp", "r")) {
		freopen("pseq.inp", "r", stdin);
		freopen("pseq.out", "w", stdout);
	}

	sieve();

	cin >> n >> s;
	FOR(i, 1, n)cin >> a[i];

	solveC();

	ll l = 1, r = 1, sum =0, res =0;
	while (r <= n) {
		sum += c[r];
		if (a[r - 1] % a[r] == 0) {
			while (sum > s)sum -= c[l++];
			res = max(res, r - l + 1);
		}
		else {
			l = r;
			sum = c[r];
		}
		r++;
	}
	cout << res;
}
