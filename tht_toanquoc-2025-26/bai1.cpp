#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	string str;
	cin>>str;
	int n = str.size();
	str = "_" + str;

	int res = 0;
	int mul = 1;
	FOD(i, n, n / 2 + 1) {
		if (str[i] == str[n - i + 1])continue;
		if (str[i] > str[n - i + 1])res += mul * (str[n - i + 1] + 10 - str[i]);
		else res += mul * (str[i] - str[n - i + 1]);
		mul *= 10;
	}
	cout << res;
}
