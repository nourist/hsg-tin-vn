#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define endl '\n'

bool p[(int)1e7 + 7];

bool isprime(ll n) {
	if (n < 2)return 0;
	if (n <= 1e7)return p[n];
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0)return 0;
	}
	return 1;
}

ll replaceStr(string str, ll n) {
	for (int i = str.size() - 1; i >= 0; i--) {
		if (str[i] == '*') {
			str[i] = n % 10 + '0';
			n /= 10;
		}
	}
	return stoll(str);
}

void solve(string str) {
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		cnt += str[i] == '*';
	}
	if (cnt == 0) {
		if (isprime(stoll(str))) {
			cout << str << endl;
		}
		else {
			cout << "Not Found" << endl;
		}
		return;
	}
	ll r = stoll(string(cnt, '9'));
	for (r; r >= 0; r--) {
		if (isprime(replaceStr(str, r))) {
			cout << replaceStr(str, r) << endl;
			return;
		}
	}
	cout << "Not Found" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("giaima.inp", "r")) {
		freopen("giaima.inp", "r", stdin);
		freopen("giaima.out", "w", stdout);
	}

	memset(p, 1, sizeof(p));
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 1e7; i++) {
		if (p[i]) {
			for (int j = i * i; j <= 1e7; j += i) {
				p[j] = 0;
			}
		}
	}

	int n;
	cin >> n;
	string str;
	while (n--) {
		cin >> str;
		solve(str);
	}
}
