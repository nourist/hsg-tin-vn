#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int d[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	int n, k, x;
	cin >> n >> k;
	set<int>s;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		s.insert(x);
		d[x]++;
	}
	cout << s.size() << endl;
	int res = 0;
	for (int i = 0; i <= 1e6; i++)res += d[i] % k;
	cout << res;
}
