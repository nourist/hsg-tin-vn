#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define name "dolech"

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);

	int n, t, i = INT_MAX, res = 0;
	cin >> n;
	while (n--) {
		cin >> t;
		i = min(i, t);
		res = max(res, t - i);
	}
	cout << res;
}
