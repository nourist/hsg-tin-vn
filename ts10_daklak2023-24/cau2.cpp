#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau2.inp", "r")) {
		freopen("cau2.inp", "r", stdin);
		freopen("cau2.out", "w", stdout);
	}

	ll m, n;
	cin >> m >> n;
#define upsqrt(n) (sqrt(n)==(ll)sqrt(n)?sqrt(n):(int)(sqrt(n)+1))
	cout << max(0LL, (ll)sqrt(n) - (ll)upsqrt(m) + 1);
}
