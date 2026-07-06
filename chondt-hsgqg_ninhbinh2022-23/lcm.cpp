#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double
#define X first
#define Y second
#define Name "lcm"

int p[(int)1e6 + 6];
int f[(int)1e6 + 6];

void sieve() {
	FOR(i, 1, 1e6)p[i] = i;
	for (int i = 2; i * i <= 1e6; i++)if (p[i] == i)for (int j = i * i; j <= 1e6; j += i)if (p[j] == j)p[j] = i;
}

void factor(int n) {
	while (n != 1) {
		f[p[n]]++;
		n /= p[n];
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

	int a, b;
	cin >> a >> b;

	sieve();

	FOR(i, a, b)factor(i);

	ll res = 1;
	FOR(i, 1, 1e6)res *= (f[i] * 2 + 1);
	cout << res;
}