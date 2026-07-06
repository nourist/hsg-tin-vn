#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll n, k, a[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("AWARDS.inp", "r")) {
		freopen("AWARDS.inp", "r", stdin);
		freopen("AWARDS.out", "w", stdout);
	}

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		if (k - a[i] >= 0) {
			res++;
			k -= a[i];
		}
		else break;
	}
	cout << res;
}
