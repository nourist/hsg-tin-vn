#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool prime(int x) {
	for (int i = 2; i * i <= x; i++)if (x % i == 0)return 0;
	return x>1;
}

#define upsqrt(n) (sqrt(n)==(int)sqrt(n)?sqrt(n):sqrt(n)+1)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	int a, b;
	cin >> a >> b;

	int res = 0;
	for (int i = upsqrt(a); i <= sqrt(b); i++) {
		if (prime(i))res++;
	}
	cout << res;
}
