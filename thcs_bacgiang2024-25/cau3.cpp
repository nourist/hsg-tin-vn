#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll d[(ll)1e6 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau3.inp", "r")) {
		freopen("cau3.inp", "r", stdin);
		freopen("cau3.out", "w", stdout);
	}

	ll n, m, x, res = 0;
	cin >> n >> m;
	while (n--) {
		cin >> x;
		d[x]++;
	}
	while (m--) {
		cin >> x;
		res += d[x];
	}
	cout << res;
}
