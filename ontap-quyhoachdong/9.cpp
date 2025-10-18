#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int d[(int)1e5 + 8][5];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, t, q, a, b;
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> t;
		d[i][t]++;
	}
	for (int i = 2; i <= n; i++) {
		d[i][1] += d[i - 1][1];
		d[i][2] += d[i - 1][2];
		d[i][3] += d[i - 1][3];
	}
	while (q--) {
		cin >> a >> b;
#define ans(l,r,x)/*[l-->r]*/ d[b][x]-d[a-1][x]
		cout << ans(a, b, 1) << " " << ans(a, b, 2) << " " << ans(a, b, 3) << endl;
	}
}
//=)) 
//AC plzz
