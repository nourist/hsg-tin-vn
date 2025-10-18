#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

string str;

int q1() {
	vector<int>f(CHAR_MAX, 0);
	int res = 0;
	for (int i : str) {
		f[i]++;
		res = max(res, f[i]);
	}
	return res;
}

int q2() {
	int cnt = 1, res = 1;
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == str[i - 1])cnt++, res = max(res, cnt);
		else {
			cnt = 1;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	cout << q1() << endl << q2();
}