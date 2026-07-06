#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e4 + 4];
int res[(int)1e4 + 4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("somax.inp", "r")) {
		freopen("somax.inp", "r", stdin);
		freopen("somax.out", "w", stdout);
	}

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	stack<int>st;
	for (int i = n; i > 0; i--) {
		while (!st.empty() && st.top() <= a[i])
			st.pop();
		if (st.empty())
			res[i] = -1;
		else
			res[i] = st.top();
		st.push(a[i]);
	}

	for (int i = 1; i <= n; i++)
		cout << res[i]<<' ';
}
