#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	int n, k, p, x, s1 =0 , s2 =0, res =0;
	cin >> n >> k >> p;
	for (int i = 0; i < n; i++) {
		cin >> x;
		s1 += k;
		s2 += x;
		if (abs(s1 - s2) <= p)res++;
	}
	cout << res;
}
