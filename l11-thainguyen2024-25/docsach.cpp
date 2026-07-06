#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll n, a[(int)2e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("docsach.inp", "r")) {
		freopen("docsach.inp", "r", stdin);
		freopen("docsach.out", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	ll sum = accumulate(a + 1, a + n + 1, 0);
	ll ma = *max_element(a + 1, a + n + 1);

	if (ma <= sum - ma) {
		cout << sum;
	}
	else {
		cout << ma * 2;
	}
}
