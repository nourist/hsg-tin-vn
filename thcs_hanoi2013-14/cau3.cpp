#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

string str;
int mPalin(ll l, ll r) {
	while (l >= 0 && r < str.size()) {
		if (str[l] == str[r]) {
			l--;
			r++;
		}
		else break;
	}
	return r - l - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau3.inp", "r")) {
		freopen("cau3.inp", "r", stdin);
		freopen("cau3.out", "w", stdout);
	}

	cin >> str;
	set<int>st(str.begin(), str.end());
	cout << st.size() << endl;
	int res = 0;
	for (int i = 1; i < str.size(); i++) {
		res = max(res, mPalin(i-1, i));
	}
	for (int i = 0; i < str.size(); i++) {
		res = max(res, mPalin(i, i));
	}
	cout << res;
}
