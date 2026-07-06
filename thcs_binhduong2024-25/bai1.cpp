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

	ll cnt = 0;
	while (n != 1) {
		if (n % 2 == 0)n /= 2;
		else if (n == 3)n--;
		else if ((n + 1) % 4 == 0)n++;
		else n--;
		cnt++;
	}
	cout << cnt;
}
