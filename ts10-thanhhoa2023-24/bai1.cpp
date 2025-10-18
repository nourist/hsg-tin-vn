#include <bits/stdc++.h>
using namespace std;

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

	ll n, s = 0;
	string x;
	cin >> n;
	while (n--) {
		cin >> x;
		s += (x.back()=='0'&&accumulate(x.begin(), x.end(), x.size()*-48)%9==0);
	}
	cout << s;
}
