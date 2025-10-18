#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, k, d[(int)1e5 + 8];
string str;

bool ok(int x) {
	for (int i = 1; i <= n; i++) {
		if (str[i - 1] == '0' && d[min(n, i + x)] - d[max(i - x - 1, 0)] >= k + 1)return 1;
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("trongcay.INP", "r", stdin);
	freopen("trongcay.OUT", "w", stdout);

	cin >> n >> k >> str;
	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + (str[i - 1] == '0');
	}

	ll l = 1, r = n;
	int res = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (ok(mid)) {
			res = min(res, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << res;
}
