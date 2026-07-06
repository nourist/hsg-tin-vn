#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)

int n, m;
string str[1001];
int h[1001][1001];
int f[1001];
int l[1001];

int d[CHAR_MAX];
int cntd = 0;

void addD(char x) {
	d[x]++;
	if (d[x] == 1)cntd++;
	else cntd--;
}

void removeD(char x) {
	d[x]--;
	if (d[x] == 1)cntd++;
	else cntd--;
}

void clearD() {
	cntd = 0;
	memset(d, 0, sizeof d);
}

void calcHeight(int j) {
	clearD();
	int top = n, bottom = n;
	while (top > 0) {
		addD(str[top][j - 1]);
		while (cntd > 3)removeD(str[bottom--][j - 1]);
		if (cntd == 3)h[bottom][j] = max(h[bottom][j], bottom-top+1);
		top--;
	}
	// while (cntd == 3) {
	// 	h[bottom][j] = max(h[bottom][j], bottom);
	// 	removeD(str[bottom][j-1]);
	// 	bottom--;
	// }
}

int solve(int i) {
	stack<int>s;
	memset(l, 0, sizeof l);
	memset(f, 0, sizeof f);
	FOD(j, m, 1) {
		if (s.empty() || h[i][s.top()] <= h[i][j])s.push(j);
		else {
			while (!s.empty() && h[i][s.top()] > h[i][j]) {
				l[s.top()] = j;
				s.pop();
			}
			s.push(j);
		}
	}
	FOR(j, 1, m) {
		f[j] = f[l[j]] + (j - l[j]) * h[i][j];
	}
	return accumulate(f + 1, f + m + 1, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("dp_c5.inp", "r")) {
		freopen("dp_c5.inp", "r", stdin);
		freopen("dp_c5.out", "w", stdout);
	}

	cin >> n >> m;

	FOR(i, 1, n) {
		cin >> str[i];
	}

	FOR(i, 1, m) {
		calcHeight(i);
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		cout << h[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	int res = 0;
	FOR(i, 1, n) {
		res += solve(i);
	}
	cout << res;
}
