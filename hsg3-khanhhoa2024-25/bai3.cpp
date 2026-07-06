#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n, m, k, q;
int cost[77][77];
vector<int>adj[77];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 70; i++)
		for (int j = 1; j <= 70; j++)
			cost[i][j] == (i == j ? 0 : 1e9);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y, t;
		cin >> x >> y >> t;
		cost[x][y] = min(cost[x][y], t);
	}

	cin >> k >> q;


}