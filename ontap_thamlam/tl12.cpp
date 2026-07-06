#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FOD(i,b,a) for(int i = b; i >= a; i--)
#define A first
#define B second
#define Name ""

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".ans", "w", stdout);
	}

	int n;
	cin >> n;

	if (n == 0) {
		cout << 10;
		return 0;
	}
	if (n == 1) {
		cout << 1;
		return 0;
	}

	string str;
	FOD(i, 9, 2) {
		while (n % i == 0) {
			char ch = i + '0';
			str += ch;
			n /= i;
		}
	}
	if (n == 1) {
		reverse(str.begin(), str.end());
		cout << str;
	}
	else {
		cout << -1;
	}
}
