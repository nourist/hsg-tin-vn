#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define X first 
#define Y second 

int n, a[(int)5e4 + 4];
int l[(int)5e4 + 4], r[(int)5e4 + 4];
ll f[(int)5e4 + 4];

struct Node {
	int i, l, r;
}v[(int)5e4 + 4];

void calcLR() {
	stack<int>st;

	FOR(i, 1, n) {
		while (a[st.top()] > a[i]) {
			r[st.top()] = i - 1;
			st.pop();
		}

		st.push(i);
	}

	while (!st.empty()) {
		r[st.top()] = n;
		st.pop();
	}

	FOD(i, n, 1) {
		while (a[st.top()] > a[i]) {
			r[st.top()] = i + 1;
			st.pop();
		}

		st.push(i);
	}

	while (!st.empty()) {
		r[st.top()] = 1;
		st.pop();
	}

	FOR(i, 1, n) {
		v[i] = { i, l[i], r[i] };
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("maxval.inp", "r")) {
		freopen("maxval.inp", "r", stdin);
		freopen("maxval.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	FOR(i, 1, n)f[i] = f[i - 1] + a[i];

	calcLR();

	sort(v + 1, v + n + 1, [&](Node x, Node y) {
		return x.r < y.r;
		});


}

/*
dp[i][k] là
*/

/*
sum(l,r) - max(l,r)
f[r]-f[l-1] - max(l,r)
f[r] - min(f[l-1]+max(l,r))
*/