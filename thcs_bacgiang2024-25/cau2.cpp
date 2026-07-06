#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool p[(int)1e6 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau2.inp", "r")) {
		freopen("cau2.inp", "r", stdin);
		freopen("cau2.out", "w", stdout);
	}

	ll n, x;
	cin >> n;

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 1e6; i++)if (p[i])for (int j = i * i; j <= 1e6; j += i)p[j] = 0;

	while (n--) {
		cin >> x;
		int sqr = sqrt(x);
		if (sqr == sqrt(x) && p[sqr])cout << "YES\n";
		else cout << "NO\n";
	}
}
