#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool p[(int)3e7 + 7];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 3e7; i++)if (p[i])for (int j = i * i; j <= 3e7; j += i)p[j] = 0;

	int n;
	cin >> n;

	int res = 0;

	for (int i = 0; i <= n; i++) {
		if (p[i] && p[n - i])res++;
		if (p[i] && p[n - i] && i == n - i)res++;
	}

	cout << res/2;
}
