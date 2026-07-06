#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int a[(int)1e5 + 5];
bool used[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("DOLLS.inp", "r")) {
		freopen("DOLLS.inp", "r", stdin);
		freopen("DOLLS.out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;
	FOR(i, 1, n)cin >> a[i];

	sort(a + 1, a + n + 1, greater<int>());
	int i = 1, j = 1;
	while (j <= n) {
		if (a[i] >= a[j] + k) {
			used[j] = 1;
			i++;
		}
		j++;
	}
	ll sum = 0;
	FOR(i, 1, n)if (!used[i])sum += a[i];
	cout << sum;
}

/*
8 2
8 4 2 1 1 3 5 9
1 1 2 3 4 5 8 9
9 8 5 4 3 2 1 1

*/