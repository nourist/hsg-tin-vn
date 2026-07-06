#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int shift1(int x, int a) {
	if (a < 0)a = (26 - (-a) % 26);
	a %= 26;
	x -= 'a';

	if (x >= a)x -= a;
	else x = x + 26 - a;

	return x + 'a';
}

int shift2(int x, int a) {
	if (a < 0)a = (26 - (-a) % 26);

	a %= 26;
	x -= 'A';

	if (x >= a)x -= a;
	else x = x + 26 - a;

	return x + 'A';
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
	int k;
	cin >> str>>k;

	string tmp = "", res = "";

	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			tmp += str[i];
		}
		else {
			if(!tmp.empty())
				res += (char)(stoll(tmp));
			tmp = "";
			if (str[i] >= 'a' && str[i] <= 'z') {
				res += shift1(str[i], k-1);
			}
			else {
				res += shift2(str[i], k);
			}
		}
	}
	if (!tmp.empty())
		res += (char)(stoll(tmp));
	cout << res;
}
