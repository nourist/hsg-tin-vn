#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double
#define X first
#define Y second
#define Name "div"

int a[(int)1e4 + 4];

int countDivisors(int x) {
	int cnt = 0;
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			cnt++;
			if (i * i != x) cnt++;
		}
	}
	return cnt;
}

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
	FOR(i, 1, n)cin >> a[i];
	int res = 0;
	FOR(i, 1, n) {
		ll sum = 0;
		ll cnt = countDivisors(a[i]);
		FOD(j, i, 1) {
			sum += a[j];
			if (sum % cnt == 0)res++;
		}
	}
	cout << res;
}