#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e5 + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("defense.inp", "r", stdin);
	freopen("defense.out", "w", stdout);

	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		for (int i = 0; i < n; i++)cin >> a[i];
		vector<int>res;
		for (int i = 0; i < n; i++) {
			if (res.empty() || res[res.size() - 1] < a[i])res.push_back(a[i]);
			else *lower_bound(res.begin(), res.end(), a[i]) = a[i];
		}
		cout << res.size() << endl;

	}
}
