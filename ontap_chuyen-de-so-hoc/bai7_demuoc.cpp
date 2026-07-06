#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int d[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai7_demuoc.inp", "r")) {
		freopen("bai7_demuoc.inp", "r", stdin);
		freopen("bai7_demuoc.out", "w", stdout);
	}

	for (int i = 1; i <= 1e6; i++) {
		for(int j = i; j <= 1e6; j += i) {
			d[j]++;
		}
	}

	int q, n;
	cin >> q;
	while (q--) {
		cin >> n;
		cout << d[n] << '\n';
	}
}
