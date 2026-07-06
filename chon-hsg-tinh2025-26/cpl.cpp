#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cpl.inp", "r")) {
		freopen("cpl.inp", "r", stdin);
		freopen("cpl.out", "w", stdout);
	}

	ll n;
	cin >> n;
	ll cnt = 0, sum = 0;
	for (int i = 1; i * i <= n; i += 2) {
		cnt++;
		sum += i * i;
	}
	cout << cnt << endl << sum;
}
