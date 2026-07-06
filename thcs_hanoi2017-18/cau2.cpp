#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau2.inp", "r")) {
		freopen("cau2.inp", "r", stdin);
		freopen("cau2.out", "w", stdout);
	}

	int n;
	cin >> n;
	unordered_map<int, int> m;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		res += m[-x];
		m[x]++;
	}
	cout << res;
}
