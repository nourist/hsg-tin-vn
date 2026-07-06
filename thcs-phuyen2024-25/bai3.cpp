#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int transform(string s) {
	return accumulate(s.begin(), s.end(), s.size() * -48) % 3;
}

int d[5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	int n;
	cin >> n;

	string str;
	while (n--) {
		cin >> str;
		d[transform(str)]++;
	}
	cout << d[0] * (d[0] - 1) / 2 + d[1] * d[2];
}
