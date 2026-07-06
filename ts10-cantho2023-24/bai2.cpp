#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

char nx(char ch) {
	if (ch == 'Z')return 'A';
	else return ch + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')str[i] = nx(str[i]);
	}
	cout << str;
}
