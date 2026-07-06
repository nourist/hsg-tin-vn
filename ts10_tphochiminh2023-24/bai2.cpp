#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

pair<int, int>v[(int)3e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v, v + n, [&](pair<int, int>x, pair<int, int>y) {
		return abs(x.first - x.second) < abs(y.first- y.second);
		});

	
}
