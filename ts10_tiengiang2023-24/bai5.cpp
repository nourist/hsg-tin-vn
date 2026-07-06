#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll solve(ll n, ll m) {
	if (n < m)swap(n, m);
	if (n % m == 0)return n / m;
	else return n / m + solve(m, n % m);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai5.inp", "r")) {
		freopen("bai5.inp", "r", stdin);
		freopen("bai5.out", "w", stdout);
	}

	ll n, m;
	cin >> n >> m;
	cout << solve(n, m);
}
