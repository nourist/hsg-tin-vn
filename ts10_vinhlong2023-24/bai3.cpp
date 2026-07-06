#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool ok(string str) {
	for (int i = 1; i < str.size(); i++)if (str[i] <= str[i - 1])return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	string str;
	cin >> str;

	if (accumulate(str.begin(), str.end(), str.size() * -48) % 9 == 0&&str.size()>1&&ok(str))cout << str;
	else cout << -1;
}
