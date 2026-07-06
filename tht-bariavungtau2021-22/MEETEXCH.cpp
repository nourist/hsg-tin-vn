#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("MEETEXCH.inp", "r")) {
		freopen("MEETEXCH.inp", "r", stdin);
		freopen("MEETEXCH.out", "w", stdout);
	}

	int n, x, s=0,res=0;
	cin >> n;
	while (n--) {
		cin >> x;
		if (x == 1)s++;
		else s--;
		res = max(res, s);
	}
	cout << res;
}
