#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)cin >> a[i];

	ll sum = 0, l = 0, r = 0, res = 0;
	while (r < n) {
		sum += a[r];
		while (sum > m) {
			sum -= a[l++];
		}
		r++;
		//        res++;
		res += r - l;
	}
	cout << res;
}
