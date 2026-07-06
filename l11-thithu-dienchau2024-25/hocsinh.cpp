#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define name "hocsinh"

int a[(int)1e6 + 10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if (fopen(name".inp", "r")) {
		freopen(name".INP", "r", stdin);
		freopen(name".OUT", "w", stdout);
	}

	int n, q, x;
	cin >> n >> q;
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	while (q--) {
		cin >> x;
		cout<<binary_search(a, a + n, x)<<'\n';
	}
}
