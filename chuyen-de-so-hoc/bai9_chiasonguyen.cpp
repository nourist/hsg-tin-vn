#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

int maxPrime(int n) {
	FOD(i, n-1, 2) {
		if (isPrime(i)) return i;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai9_chiasonguyen.inp", "r")) {
		freopen("bai9_chiasonguyen.inp", "r", stdin);
		freopen("bai9_chiasonguyen.out", "w", stdout);
	}

	int n;
	cin >> n;
	int cnt = 1;
	while(!isPrime(n)&&n>1) {
		cnt++;
		n -= maxPrime(n);
	}
	cout << cnt;
}
