#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

string strTransf(string str) {
	string res = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9')res += str[i];
	}
	return res;
}

string maxStr(string str, int k) {
	stack<char>st;
	for (int i = 0; i < str.size(); i++) {
		if (st.empty())st.push(str[i]);
		else {
			while (!st.empty() && st.top() < str[i] && k > 0) {
				st.pop();
				k--;
			}
			st.push(str[i]);
		}
	}
	while (!st.empty() && k > 0) {
		st.pop();
		k--;
	}
	string res = "";
	while (!st.empty()) {
		res = st.top() + res;
		st.pop();
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("cau2.inp", "r", stdin);
	// freopen("cau2.out", "w", stdout);

	string str;
	ll k;
	cin >> str >> k;

	str = strTransf(str);

	cout << maxStr(str, str.size() - k);
}
