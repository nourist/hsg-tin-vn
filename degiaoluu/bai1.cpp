#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define lcm(a,b) (a/__gcd(a,b)*b)

bool ok(int n) {
	int sum = 1, a = n;
	while (n != 0) {
		if (n % 10 == 0)return 0;
		sum = lcm(sum, (n % 10));
		n /= 10;
	}
	return a % sum == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	int a, b;
	cin >> a >> b;

	vector<int>res;
	FOR(i, a, b)if (ok(i))res.push_back(i);

	if (res.size() == 0)cout << -1;
	else {
		cout << res.size() << endl;
		for (auto i : res)cout << i << ' ';
	}
}
