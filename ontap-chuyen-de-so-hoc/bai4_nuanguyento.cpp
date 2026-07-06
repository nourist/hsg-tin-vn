#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (long long i = l; i <= r; ++i)
#define FOD(i,r,l) for (long long i = r; i >= l; --i)
#define ll long long
#define ld long double

bool p[(int)1e7 + 7];
int c[(int)1e7 + 7];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai4_nuanguyento.inp", "r")) {
		freopen("bai4_nuanguyento.inp", "r", stdin);
		freopen("bai4_nuanguyento.out", "w", stdout);
	}

	memset(p, 1, sizeof(p));
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= (int)1e7; ++i) {
		if (p[i]) {
			for (int j = i * i; j <= (int)1e7; j += i) {
				p[j] = 0;
			}
		}
	}

	FOR(i, 2, (int)1e7) {
		if (p[i])
			for (int j = i; j <= (int)1e7; j += i) {
				c[j]++;
			}
	}

	FOR(i, 2, 1e7)c[i] = (c[i] == 2);
	for (int i = 2; i * i <= 1e7; i++) {
		if (p[i]) {
			for (int j = i * i; j <= 1e7; j += i * i) {
				c[j] = 0;
			}
		}
	}
	for (int i = 2; i * i <= 1e7; i++) {
		if(p[i])
		c[i * i] = 1;
	}
	int n;
	cin >> n;
	ll sum = 0;
	FOR(i, 1, n) {
		if (c[i])sum += i;
	}
	cout << n << ' ' << sum;
}