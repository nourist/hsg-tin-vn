#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool ok(int n) {
	int s = 0;
	while (n != 0) {
		s += (n % 10) * (n % 10);
		n /= 10;
	}
	for(int i = 2; i*i <= s; i++) {
		if(s % i == 0) {
			return false;
		}
	}
	return s>1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau1.inp", "r")) {
		freopen("cau1.inp", "r", stdin);
		freopen("cau1.out", "w", stdout);
	}

	int n;
	cin >> n;
	n++;
	while (!ok(n)) {
		n++;
	}
	cout << n << endl;
}
