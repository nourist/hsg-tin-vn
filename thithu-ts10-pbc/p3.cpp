#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

int n, a[(int)1e5 + 5];

void sub2() {
	int sum1 = 0, sum2 = 0;
	double res = 1e9;;
	FOR(i, 1, n - 2) {
		sum1 += a[i];
		sum2 = 0;
		FOD(j, n, i + 2) {
			sum2 += a[j];
			res = min(res, (double)(a[i] + a[j]) / (i + n - j + 1));
		}
	}
	cout << fixed << setprecision(3) << res;
}

void sub3() {
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("p3.inp", "r")) {
		freopen("p3.inp", "r", stdin);
		freopen("p3.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	// if (n <= 1000) {
		sub2();
	// }
	// else {
	// 	sub3();
	// }
}
