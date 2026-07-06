#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int d[(int)1e5 + 5], r[(int)1e5 + 5], n;

int smaller(int a, int b) {
	if ((ll)d[a] * r[a] == (ll)d[b] * r[b]) return d[a] < d[b];
	return (ll)d[a] * r[a] < (ll)d[b] * r[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	cin >> n;
	FOR(i, 0, n-1)cin >> d[i] >> r[i];

	reverse(d, d + n);
	reverse(r, r + n);

	vector<int>lis;
	FOR(i, 0, n-1) {
		if (lis.empty() || smaller(lis.back(), i)) {
			lis.push_back(i);
		} else {
			*lower_bound(lis.begin(), lis.end(), i, smaller) = i;
		}
	}
	cout<<lis.size()<<endl;
}
