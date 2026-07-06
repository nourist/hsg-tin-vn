#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool strGreater(string a, string b) {
	while (!a.empty() && a[0] == '0')a.erase(0, 1);
	while (!b.empty() && b[0] == '0')b.erase(0, 1);
	if (a.size() != b.size()) return a.size() > b.size();
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) return a[i] > b[i];
	}
	return 0;
}

string Stransform(string str) {
	while (!str.empty() && str[0] == '0')str.erase(0, 1);
	return str;
}


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

	string res = "0", tmp = "";
	for (int i = 0; i < str.size(); i++) {
		if(str[i]>='0' && str[i]<='9')tmp += str[i];
		else {
			if (!tmp.empty() && strGreater(tmp, res))res = Stransform(tmp);
			tmp = "";
		}
	}
	if (!tmp.empty() && strGreater(tmp, res))res = Stransform(tmp);
	cout << res;
}
