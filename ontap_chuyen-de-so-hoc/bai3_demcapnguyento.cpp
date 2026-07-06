#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double


bool isPrime(ll n) {
	if (n < 2) return false;
	for (ll i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3_demcapnguyento.inp", "r")) {
		freopen("bai3_demcapnguyento.inp", "r", stdin);
		freopen("bai3_demcapnguyento.out", "w", stdout);
	}

	int n, x,cnt =0;
	cin >> n;
	while (n--) {
		cin >> x;
		if(isPrime(x)) cnt++;
	}
	cout<<cnt*(cnt+1)/2 << endl;
}
