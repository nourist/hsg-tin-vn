#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int d1[CHAR_MAX];
int d2[CHAR_MAX];

bool ok() {
	for (int i = 0; i < CHAR_MAX; i++)if (d1[i] != d2[i])return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;

	for (int i = 0; i < n; i++)d1[a[i]]++;
	for (int i = 0; i < n - 1; i++)d2[b[i]]++;
	int res = 0;
	for (int i = n - 1; i < m; i++) {
		d2[b[i]]++;

		res += ok();

		d2[b[i - n + 1]]--;
	}
	cout << res;
}
