#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll pow10[16];
ll digit[16];

ll solve(ll k) {
	ll idx = 1;
	while (digit[idx] < k) {
		idx++;
	}

	k -= digit[idx - 1];
	ll num = pow10[idx - 1] + (k-1) / idx;
	string s = to_string(num);
	return s[(k-1)%idx];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	pow10[0] = 1;
	for (int i = 1; i <= 14; i++) {
		pow10[i] = pow10[i - 1] * 10;
		digit[i] = (pow10[i] - pow10[i - 1]) * i + digit[i-1];
	}

	ll k;
	cin >> k;
	cout << (char)solve(k) << (char)solve(k + 1) << (char)solve(k + 2) << (char)solve(k + 3);
}
