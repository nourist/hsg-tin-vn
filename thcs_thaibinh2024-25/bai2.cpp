#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e4 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	ll n, m;
	cin >> n >> m;
	while (n--) {
		for (ll t,i = 0; i < m; i++) {
			cin >> t;
			a[i] += t;
		}
	}
	for (int i = 0; i < m; i++)cout << a[i] << ' ';
}
