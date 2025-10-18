#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

struct DATA {
	int p = 0, k, c;
}v[(int)1e4 + 10];
int dp[(int)1e4 + 10];

bool cmp(DATA x, DATA y) {
	return x.k < y.k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("DPHT3.inp", "r", stdin);
	freopen("DPHT3.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i].p >> v[i].k >> v[i].c;
	}

	sort(v + 1, v + n + 1, cmp);

	for (int i = 1; i <= n; i++) {
		DATA val;
		val.k = v[i].p;
		auto it = upper_bound(v + 1, v + n + 1, val, cmp);
		if (it == v + n + 1)dp[i] = max(dp[i - 1], v[i].c);
		else dp[i] = max(dp[i - 1], dp[(it - v - 1)] + v[i].c);
	}
	cout << dp[n];
}
