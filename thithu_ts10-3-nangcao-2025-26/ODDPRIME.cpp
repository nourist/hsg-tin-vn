#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

bool p[(int)1e7 + 7];

int solve(int n) {
	while (n % 2 == 0) n /= 2;
	return n*p[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("ODDPRIME.inp", "r")) {
		freopen("ODDPRIME.inp", "r", stdin);
		freopen("ODDPRIME.out", "w", stdout);
	}

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 1e7; i++)if (p[i])for (int j = i * i; j <= 1e7; j += i)p[j] = 0;

	int l, r;
	cin >> l >> r;

	int res = 0;
	FOR(i, l, r) {
		res += solve(i);
	}
	cout << res;
}
