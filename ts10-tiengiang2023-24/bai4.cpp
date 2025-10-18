#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int d[CHAR_MAX];

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
	for (int i = 'a'; i <= 'z'; i++) {
		cin >> d[i];
	}
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '*') {
			for (int j = 'a'; j <= 'z'; j++) {
				if (d[j] != 0) {
					str[i] = j;
					d[j]--;
					break;
				}
			}
		}
	}
	cout << str;
}
