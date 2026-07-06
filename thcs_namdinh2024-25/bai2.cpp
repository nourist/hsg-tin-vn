#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int d[CHAR_MAX];

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

	for (int i = 0; i < str.size(); i++)d[tolower(str[i])]++;
	int res = 0;
	for (int i = 'a'; i <= 'z'; i++)res += d[i]*(d[i]>1);
	cout << res << endl;
	memset(d, 0, sizeof d);
	for (int i = 0; i < str.size(); i++) {
		str[i] = tolower(str[i]);
		if (d[str[i]] == 0&&str[i]!=' ')cout << str[i];
		d[str[i]] = 1;
	}
}
