#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("choxuan.inp", "r")) {
		freopen("choxuan.inp", "r", stdin);
		freopen("choxuan.out", "w", stdout);
	}

	ll n, k;
	cin >> n >> k;

	cout << max(-1LL, n - k * 7);
}
