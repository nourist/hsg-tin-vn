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
	while (getline(cin, str)) {
		stringstream ss(str);
		
		bool block = 1;
		string s;
		while (ss >> s) {
			if (s[0] >= 'a' && s[0] <= 'z' || (s[0] >= 'A' && s[0] <= 'Z')) {
				if (!block)cout << ' ';
				cout << s;
				block = 0;
			}
			else if(s=="("||s==")"||s=="."||s==","||s==";"||s==":"||s=="?"||s=="!") {
				cout << s;
				if (s == "(")block = 1;
			}
			else {
				if (!block)cout << ' ';
				cout << s;
				block = 0;
			}
		}
		cout << endl;
	}
}
