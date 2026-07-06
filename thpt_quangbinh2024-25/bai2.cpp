#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool p[(int)1e6 + 6];
int n, a[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 1e6; i++) {
		if (p[i]) {
			for (int j = i * i; j <= 1e6; j += i) {
				p[j] = 0;
			}
		}
	}

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int cnt = 0, res = 0;
	for(int i = 1; i <= n; i++) {
		if (p[a[i]]) {
			cnt++;
		} else {
			res = max(res, cnt);
			cnt = 0;
		}
	}
	if (cnt > 0) {
		res = max(res, cnt);
	}
	cout << res;
}
