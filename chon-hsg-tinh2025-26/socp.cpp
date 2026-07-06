#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

ll n, x;
bool d[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("socp.inp", "r")) {
		freopen("socp.inp", "r", stdin);
		freopen("socp.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n) {
		cin >> x;
		if (sqrt(x) * sqrt(x) == x) d[(int)sqrt(x)] = 1;
	}
	int cnt = 0, i = 0;
	while (cnt < 3) {
		if (!d[i]) {
			cnt++;
			cout << i * i << ' ';
		}
		i++;
	}
}
