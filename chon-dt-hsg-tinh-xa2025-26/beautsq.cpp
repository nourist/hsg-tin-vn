#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

#define upsqrt(n) (sqrt(n)==(ll)sqrt(n)?(ll)sqrt(n):(ll)sqrt(n)+1)

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

bool isPalindrome(int n) {
	int rev = 0, tmp = n;
	while (tmp) {
		rev = rev * 10 + tmp % 10;
		tmp /= 10;
	}
	return rev == n;
}

bool ok(int n) {
	return isPrime(n) && isPalindrome(n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("beautsq.inp", "r")) {
		freopen("beautsq.inp", "r", stdin);
		freopen("beautsq.out", "w", stdout);
	}

	ll a, b;
	cin >> a >> b;

	int res = 0;
	FOR(i, upsqrt(a), sqrt(b)) {
		res += ok(i);
	}
	cout << res;
}
