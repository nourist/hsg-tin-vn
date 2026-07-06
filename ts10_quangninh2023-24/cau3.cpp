#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int d[(int)3e5 + 10];
vector<int>a[(int)3e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau3.inp", "r")) {
		freopen("cau3.inp", "r", stdin);
		freopen("cau3.out", "w", stdout);
	}

	for (int i = 1; i <= 3e5; i++) {
		for (int j = i; j <= 3e5; j += i) {
			d[j]++;
		}
	}

	ll n, k, res = 0;
	cin >> n >> k;

	int mx = 0;
	for (int i = 1; i <= n; i++) {
		a[d[i]].push_back(i);
		mx = max(mx, d[i]);
	}

	for (int dx = 1; dx <= mx; dx++) {
		for (int dy = 1; dy <= mx; dy++) {
			ll left = k * dx * dy;
			int i = 0, j = a[dy].size() - 1;
			while (i < a[dx].size() && j >= 0 && a[dx][i] <= a[dy][j]) {
				ll sum = a[dx][i] * a[dy][j];
				if (sum == left) {
					res++;
					i++;
					j--;
				}
				else if (sum < left) {
					i++;
				}
				else {
					j--;
				}
			}
		}
	}

	cout << res;
}
