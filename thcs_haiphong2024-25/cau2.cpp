#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

string normalize(string str) {
	while (str.size() > 1 && str[0] == '0')str.erase(0, 1);
	return str;
}

bool cp(string str){
	ll n = stoll(str);
	// cerr << n << endl;
	return sqrt(n) == (int)sqrt(n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau2.inp", "r")) {
		freopen("cau2.inp", "r", stdin);
		freopen("cau2.out", "w", stdout);
	}

	string str;
	cin >> str;

	string tmp = "";
	ll res = -1;
	for (int i = 0; i < str.size(); i++) {
		if (isdigit(str[i]))tmp += str[i];
		else if (!tmp.empty()) {
			if (cp(normalize(tmp)))
				res = max(res, stoll(normalize(tmp)));
			tmp = "";
		}
	}
	if (!tmp.empty() && cp(normalize(tmp)))res = max(res, stoll(tmp));
	cout << res;
}
