#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	int n, m, ch1, ch2, k;
	string s1, s2;
	cin >> n >> s1 >> m >> s2 >> k;

	if (s1 == "R")cout << min(k, n);
	else cout << max(0, min({ m, k - n }));
}
