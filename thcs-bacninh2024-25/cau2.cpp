#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool p[(int)6e6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau2.inp", "r")) {
		freopen("cau2.inp", "r", stdin);
		freopen("cau2.out", "w", stdout);
	}

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 5e6; i++) {
		if (p[i]) {
			for (int j = i * i; j <= 5e6; j += i) {
				p[j] = 0;
			}
		}
	}

	string str;
	cin >> str;

	int res = 0;

	for (int i = 0; i < str.size(); i++) {
		if (!isdigit(str[i]))
			continue;

		int num = 0;
		for (int j = i; j <= str.size() && j - i <= 6; j++) {
			if (!isdigit(str[j]))
				break;
			num *= 10;
			num += str[j] - '0';
			if (num <= 5e6 && p[num])
				res = max(res, num);
		}
	}

	cout << res;
}
