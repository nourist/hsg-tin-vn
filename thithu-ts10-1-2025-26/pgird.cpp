#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

int n, m;
int a[(int)1e3 + 3][(int)1e3 + 3];

int solveRow(int i) {
	int l = m / 2;
	int r = l + 1 + (m % 2);
	int cnt = 0;
	while (l >= 1 && r <= m) {
		cnt += (a[i][l] != a[i][r]);
		l--;
		r++;
	}
	return cnt;
}

int solveCol(int j) {
	int t = n / 2;
	int b = t + 1 + (n % 2);
	int cnt = 0;
	while (t >= 1 && b <= n) {
		cnt+=(a[t][j] != a[b][j]);
		t--;
		b++;
	}
	return cnt;
}

int solveX() {
	int res = 0;
	FOR(i, 1, n)res+=solveRow(i);
	return res;
}

int solveY() {
	int res = 0;
	FOR(j, 1, m)res+=solveCol(j);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("pgrid.inp", "r")) {
		freopen("pgrid.inp", "r", stdin);
		freopen("pgrid.out", "w", stdout);
	}

	cin >> n >> m;
	FOR(i, 1, n)FOR(j, 1, m)cin >> a[i][j];
	cout << min(solveX(), solveY());
}
