#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e6 + 6];
int p[(int)1e6 + 6];
int d[(int)1e6 + 6];
int cnt = 0;

void add(int x) {
	d[x]++;
	if (d[x] % 2 == 0)cnt--;
	else cnt++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("game.inp", "r")) {
		freopen("game.inp", "r", stdin);
		freopen("game.out", "w", stdout);
	}

	for (int i = 1; i <= 1e6; i++) {
		p[i] = i;
	}

	for (int i = 2; i * i <= 1e6; i++) {
		if (p[i] == i) {
			for (int j = i * i; j <= 1e6; j += i) {
				if (p[j] == j) {
					p[j] = i;
				}
			}
		}
	}

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}


	for (int i = 1; i <= n; i++) {
		while (p[a[i]] != 1) {
			add(p[a[i]]);
			a[i] /= p[a[i]];
		}

		cout << (cnt == 0 ? "YES " : "NO ");
	}
}
