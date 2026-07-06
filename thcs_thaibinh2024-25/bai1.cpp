#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool isPrime(ll n) {
	for(ll i = 2; i * i <= n; ++i) {
		if(n % i == 0) return false;
	}
	return n>1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	string str;
	cin >> str;
	ll sum = accumulate(str.begin(), str.end(), str.size() * -'0');
	cout << (isPrime(sum) ? "YES" : "NO");
}
