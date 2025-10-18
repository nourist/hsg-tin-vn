#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau3.inp", "r")) {
		freopen("cau3.inp", "r", stdin);
		freopen("cau3.out", "w", stdout);
	}

	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i += 2) {
		int n = str[i + 1] - '0';
		char ch = str[i] + n;
		if (ch > 'Z')cout << (char)(ch - 'Z' + 'A'-1);
		else cout << ch;
	}
}
