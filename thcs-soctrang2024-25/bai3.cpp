#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int l[(int)1e5 + 5];
vector<int>a[102];
vector<int>res[102];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	int n;
	cin >> n;

	set<int>st;
	for (int i = 1; i <= n; i++) { cin >> l[i]; }
	for (int i = 1; i <= n; i++) {
		for (int t, j = 1; j <= l[i]; j++) {
			cin >> t;
			a[t].push_back(i);
			st.insert(t);
		}
	}

	for (int i : st) {
		int group = a[i][0];
		for (int j : a[i]) {
			if (l[j] < l[group]) {
				group = j;
			}
			if (l[j] == l[group])group = min(group, j);
		}
		res[group].push_back(i);
		// res[i].push_back(group);
	}
	for (int i = 1; i <= n; i++) {
		cout << i << ' ';
		for (int j : res[i])cout << j << ' ';
		cout << '\n';
	}
}
