#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define X first
#define Y second

pair<int, int>v[(int)1e4 + 4];
int dp[(int)1e4 + 4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("TEAMCOMP.inp", "r")) {
		freopen("TEAMCOMP.inp", "r", stdin);
		freopen("TEAMCOMP.out", "w", stdout);
	}

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)cin >> v[i].X >> v[i].Y;

	sort(v + 1, v + n + 1, [&](pair<int, int> a, pair<int, int> b) {
		return a.Y < b.Y;
		});

	for (int i = 1; i <= n; i++)dp[i] = v[i].Y - v[i].X;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[j] + v[i].Y - v[i].X - 2*max(0, v[j].Y - v[i].X));
		}
	}
	cout << *max_element(dp + 1, dp + n + 1);
}

/*
7
1 4
0 8
7 8
10 12
7 10
5 6
11 12

1 4
5 6
0 8
7 8
7 10
10 12
11 12

*/