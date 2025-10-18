#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau3.inp", "r")) {
		freopen("cau3.inp", "r", stdin);
		freopen("cau3.out", "w", stdout);
	}

	int k;
	string str;
	cin >> k >> str;
	vector<string>v;
	for (int i = 1; i <= str.size(); i++) {
		v.push_back(str);
		str.push_back(str[0]);
		str.erase(0, 1);
	}
	sort(v.begin(), v.end());
	if (k >= v.size()||k<=0) {
		cout << -1;
		return 0;
	}
	cout << v[k - 1];
}
