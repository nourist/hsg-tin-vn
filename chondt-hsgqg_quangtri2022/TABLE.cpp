#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); i++)
#define FOD(i,r,l) for (int i = (r); i >= (l); i--)
#define ll long long
#define db double
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "table"

int n, m;
int a[1003][1003];
int h[1003][1003];
int f[1003][1003];
int l[1003], r[1003];
int id[1003];
int mx[1003];

void solveRow(int i) {
	memset(l, 0, sizeof l);
	memset(r, 0, sizeof r);
	stack<int>st;
	FOR(j, 1, m) {
		while (!st.empty() && h[i][st.top()] > h[i][j]) {
			r[st.top()] = j;
			st.pop();
		}
		st.push(j);
	}
	while (!st.empty()) {
		r[st.top()] = m + 1;
		st.pop();
	}
	FOD(j, m, 1) {
		while (!st.empty() && h[i][st.top()] > h[i][j]) {
			l[st.top()] = j;
			st.pop();
		}
		st.push(j);
	}
	FOR(j, 1, m)id[j] = j;
	sort(id + 1, id + m + 1, [&](int x, int y) {
		return h[i][x] < h[i][y];
		});

	// FOR(j, 1, m)cout << id[j] << ' ' << r[id[j]] - l[id[j]] - 1 << ' ';
	// cout << endl;

	FOD(j, m, 1)mx[j] = max(mx[j + 1], r[id[j]] - l[id[j]] - 1);

	int cur = 0;
	FOR(j, i, n) {
		while (cur + 1 <= m && h[i][id[cur + 1]] < j - i + 1)cur++;
		f[i][j] = max(f[i][j], mx[cur + 1] * (j - i + 1));
	}
}

void solve() {
	FOR(i, 1, n)solveRow(i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> m;
	FOR(i, 1, n)FOR(j, 1, m)cin >> a[i][j];

	FOD(i, n, 1)FOR(j, 1, m) {
		if (a[i][j] <= 1) {
			h[i][j] = h[i + 1][j] + 1;
		}
		else {
			h[i][j] = 0;
		}
	}

	solve();

	memset(h, 0, sizeof h);

	FOD(i, n, 1)FOR(j, 1, m) {
		if (a[i][j] >= 1) {
			h[i][j] = h[i + 1][j] + 1;
		}
		else {
			h[i][j] = 0;
		}
	}
	solve();

	// FOR(i, 1, n)FOR(j, 1, n)cout << f[i][j] << " \n"[j == m];

	FOR(len, 2, n)FOR(i, 1, n - len + 1) {
		int j = i + len - 1;
		f[i][j] = max({ f[i][j],f[i + 1][j],f[i][j - 1] });
	}

	int q;
	cin >> q;
	while (q--) {
		int i, j;
		cin >> i >> j;
		cout << f[i][j] << '\n';
	}
}