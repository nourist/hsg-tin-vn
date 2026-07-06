#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)

int n, m;
int h[1001][1001];
int f[1001];
int l[1001];

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
	return accumulate(f+1,f+m+1,0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("dp_c4.inp", "r")) {
		freopen("dp_c4.inp", "r", stdin);
		freopen("dp_c4.out", "w", stdout);
	}

	cin >> n >> m;

	FOR(i,1,n) {
		FOR(j, 1, m) {
			int t;
			cin >> t;
			if (t == 1)
				h[i][j] = h[i - 1][j] + 1;
		}
	}

	int res = 0;
	FOR(i, 1, n) {
		res += solve(i);
	}
	cout << res;
}
