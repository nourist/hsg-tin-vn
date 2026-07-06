#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int d1[255], d2[255];

bool ok() {
	for (int i = 'a'; i <= 'z'; i++) {
		if (d1[i] != d2[i])return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau3.inp", "r")) {
		freopen("cau3.inp", "r", stdin);
		freopen("cau3.out", "w", stdout);
	}

	int n;
	string str;
	cin >> n>>str;

	string res = "";
	for (int i = 0; i < n; i++)d2[str[i]]++;
	for (int i = 0; i < n; i++) {
		res += str[i];
		d2[str[i]]--;
		if (d1[str[i]] <= str[i] - 'a')d1[str[i]]++;
		if (ok()) {
			cout << res;
		}
	}
}

