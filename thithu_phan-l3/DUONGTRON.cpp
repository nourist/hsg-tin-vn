#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define X first 
#define Y second 

pii a[(int)1e5 + 5];
vector<int>adj[(int)1e5 + 5];

bool contain(int par, int child) {
	return a[par].X <= a[child].X && a[par].Y >= a[child].Y;
}

bool ok(int u) {
	if (adj[u].empty() || adj[u].size() == 1)return 0;

	if (a[u].X != a[adj[u].front()].X || a[u].Y != a[adj[u].back()].Y)return 0;

	FOR(i, 1, adj[u].size() - 1) {
		if (a[adj[u][i - 1]].Y != a[adj[u][i]].X)return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("DUONGTRON.inp", "r")) {
		freopen("DUONGTRON.inp", "r", stdin);
		freopen("DUONGTRON.out", "w", stdout);
	}

	int n;
	cin >> n;

	FOR(i, 1, n) {
		int x, r;
		cin >> x >> r;

		a[i].X = x - r;
		a[i].Y = x + r;
	}

	sort(a + 1, a + n + 1, [&](pii x, pii y) {
		if (x.X != y.X)return x.X < y.X;
		return x.Y > y.Y;
		});

	stack<int> st;

	FOR(i, 1, n) {
		while (!st.empty() && !contain(st.top(), i)) {
			st.pop();
		}

		if (!st.empty())
			adj[st.top()].push_back(i);

		st.push(i);
	}

	int res = n + 1;
	FOR(i, 1, n) {
		res += ok(i);
	}
	cout << res;
}
