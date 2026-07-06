#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	string str;
	string tmp = "hello";
	while (getline(cin, str)) {
		int j = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == tmp[j]) {
				j++;
			}
			if(j==tmp.size())break;
		}
		cout << (j == tmp.size() ? "YES" : "NO") << endl;
	}
}
