#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

int a[(int)1e5 + 5];
vector<int>res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("LEAD.inp", "r")) {
		freopen("LEAD.inp", "r", stdin);
		freopen("LEAD.out", "w", stdout);
	}

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		FOR(i, 1, n)cin >> a[i];
		res.clear();
		int mm = -1e9;
		FOD(i, n, 1) {
			if (a[i] > mm)res.push_back(a[i]);
			mm = max(mm, a[i]);
		}
		FOD(i, res.size() - 1, 0)cout << res[i] << ' ';
		cout << endl;
	}
}
