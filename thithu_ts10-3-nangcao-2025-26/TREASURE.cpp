#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

int n, k, a[505], dp[160160];

int getdp(int i) {
	return dp[i + 80008];
}

void setdp(int i, int v) {
	dp[i + 80008] = v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("TREASURE.inp", "r")) {
		freopen("TREASURE.inp", "r", stdin);
		freopen("TREASURE.out", "w", stdout);
	}

	cin >> n >> k;
	FOR(i, 1, n) cin >> a[i], a[i]-=k;

	setdp(0, 1);
	FOR(i, 1, n) {
		FOD(j, 80000, -80000) {
			setdp(j + a[i], getdp(j + a[i]) + getdp(j));
		}
	}
	cout<<getdp(0) - 1 << endl; 
}
