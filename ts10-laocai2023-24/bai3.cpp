#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

string str;
bool ok(string sub) {
	if (str.size() % sub.size() != 0)return 0;
	string tmp = "";
	for (int i = 0; i < str.size() / sub.size(); i++) {
		tmp += sub;
	}
	return tmp == str;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	cin >> str;
	for (int i = 1; i <= str.size(); i++) {
		if (ok(str.substr(0, i))) {
			cout << str.substr(0, i);
			return 0;
		}
	}
}
