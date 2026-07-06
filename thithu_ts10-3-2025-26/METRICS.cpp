#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

ll n,m,a[(int)1e5 + 5], b[(int)1e5 + 5], f1[(int)1e4 + 4], f2[(int)1e4 + 4], s1[(int)1e4 + 4], s2[(int)1e4 + 4];

void sub2() {
	ll res = 0;
	FOR(i, 1, n) {
		FOR(j, 1, m) {
			res += abs(a[i] - b[j])*(i-j);
		}
	}
	cout << res;
}

void sub3() {
	FOR(i, 1, n)f1[a[i]]++, s1[a[i]] += i;
	FOR(i, 1, m)f2[b[i]]++, s2[b[i]] += i;

	int m1 = *max_element(a + 1, a + n + 1);
	int m2 = *max_element(b + 1, b + m + 1);

	ll res = 0;
	FOR(i, 1, m1)FOR(j, 1, m2) {
		if (f1[i] != 0 && f2[j] != 0) {
			res += (s1[i] * f2[j] - s2[j]) * abs(i - j);
		}
	}
	cout << res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("METRICS.inp", "r")) {
		freopen("METRICS.inp", "r", stdin);
		freopen("METRICS.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	cin >> m;
	FOR(i, 1, m)cin >> b[i];

	if (n * m <= 5e7) {
		sub2();
	}
	else {
		sub3();
	}
}
