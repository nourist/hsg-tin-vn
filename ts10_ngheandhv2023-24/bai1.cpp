#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	ll n;
	cin >> n;
	ll res = 0, cnt = 1;
	for (int i = 1; i <= n; i++) {
		if(i%2==0)
		cnt *= 2;
		res += cnt;
	}
	cout << res;
}
