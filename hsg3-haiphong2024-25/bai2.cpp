#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	ll sum = 0, res = -1;
	ll l = 1, r = 1;
	while (r <= n) {
		sum += a[r];

		while (sum >= k) {
			res = max(res, sum / (r - l+1));
			sum -= a[l++];
		}

		r++;
	}

	if (res == -1)cout << "NO";
	else cout << res;
}

/*

5 6
0 1 5 4  2  3
0 1 6 10 12 15

6 ->0
10->1
12->6
15->6

3 6
1 -5 2
1 -4 -2

*/