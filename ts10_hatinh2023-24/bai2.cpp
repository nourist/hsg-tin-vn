#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool isp(ll n) {
	for (int i = 2; i * i <= n; i++)if (n % i == 0)return 0;
	return n > 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	ll n;
	cin >> n;
	ll s = 0;
	while (n != 0) {
		s += (n % 10)*(n%10);
		n /= 10;
	}
	cout << (isp(s) ? 1 : -1)<<endl<<s;
}
