#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool p[(int)1e7];

int sum(int n) {
	int s = 0;
	while (n != 0) {
		int t = n % 10;
		s += t*t;
		n /= 10;
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i < 1e7; i++) {
		if (p[i]) {
			for (int j = i * i; j < 1e7; j+=i) {
				p[j] = 0;
			}
		}
	}

	int n;
	cin >> n;

	int cnt = 0, i = 11;
	while (1) {
		if (p[sum(i)]) {
			cnt++;
		}
		if (cnt == n) {
			cout << i;
			return 0;
		}
		i++;
	}

}
