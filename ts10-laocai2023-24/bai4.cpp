#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = toupper(str[i]);
		}
		else {
			str[i] = tolower(str[i]);
		}
	}
	sort(str.begin(), str.end(), greater<char>());
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = toupper(str[i]);
		}
		else {
			str[i] = tolower(str[i]);
		}
	}
	cout << str;
}
