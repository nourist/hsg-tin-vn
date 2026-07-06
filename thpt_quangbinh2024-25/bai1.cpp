#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool ok(string s) {
	for (int i = 0; i < s.size(); i++) {
		if(s[i]!=s[s.size()-1-i]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	int n;
	cin>>n;

	string s;
	int res = 0;
	while(n--){
		cin>>s;
		res += ok(s);
	}
	cout << res;
}
