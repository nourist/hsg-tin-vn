#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	ll n;
	cin >> n;

	vector<int>res;
	while (n != 0) {
		res.push_back((n - 1) % 2+1);
		n = (n - 1) / 2;
	}
	for(int i = res.size() - 1; i >= 0; i--) {
		cout << (res[i]==1?"5":"8");
	}
}

/*

1: 1
2: 2
3: 11
4: 12
5: 21

*/