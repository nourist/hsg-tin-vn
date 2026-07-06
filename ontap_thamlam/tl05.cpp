#include <bits/stdc++.h>
using namespace std;

#define Name "dutrunuoc"

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

int a[(int)1e6 + 6], b[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n;
	cin >> n;

	ll sum = 0;

	FOR(i, 1, n)cin >> a[i] >> b[i], sum += b[i] - a[i];

	sort(b + 1, b + n + 1, greater<int>());
	if (sum == 0) { cout << 0; return 0; }
	FOR(i, 1, n) {
		sum -= b[i];
		if (sum <= 0) {
			cout << i;
			return 0;
		}
	}
}
