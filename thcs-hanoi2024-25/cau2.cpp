#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau2.inp", "r")) {
		freopen("cau2.inp", "r", stdin);
		freopen("cau2.out", "w", stdout);
	}

	string str, tmp = "", res = "";
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i]>='0'&&str[i]<='9')tmp += str[i];
		else {
			res += string(stoi(tmp), str[i]);
			tmp = "";
		}
	}
	for (int i = 0; i < res.size(); i++) {
		if (res[i] == 'A')res[i]= 'T';
		else if (res[i] == 'G')res[i]= 'C';
		else if (res[i] == 'T')res[i]= 'A';
		else res[i]= 'G';
	}
	cout << res;
}
