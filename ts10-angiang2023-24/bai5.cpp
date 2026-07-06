#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai5.inp", "r")) {
		freopen("bai5.inp", "r", stdin);
		freopen("bai5.out", "w", stdout);
	}

	string str;
	cin >> str;
	ll d = stoll(str.substr(0,2));
	ll m = stoll(str.substr(2,2));
	ll y = stoll(str.substr(4,4));

	vector<int>days = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)days[2] = 29;

	if (d>days[m]) {
		cout << "Khong tim duoc";
	}
	else if (d == days[m] && m < 12) {
		cout << "01";
		if (m + 1 < 10)cout << 0 << m + 1;
		else cout << m + 1;
		cout << y;
	}
	else if (d == days[m]) {
		cout << "0101" << y+1;
	}
	else {
		if (d + 1 < 10)cout << 0 << d + 1;
		else cout << d + 1;
		if (m < 10)cout << 0 << m;
		else cout << m;
		cout<< y;
	}
}