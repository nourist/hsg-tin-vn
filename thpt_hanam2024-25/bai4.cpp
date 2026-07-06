#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)2e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];

	int res = 0;
	stack<int>st;
	for (int i = 1; i <= n; i++) {
		while (!st.empty() && st.top() < a[i])st.pop(), res++;
		res += !st.empty();
		while (!st.empty() && st.top() <= a[i])st.pop();
		st.push(a[i]);
	}
	cout << res;
}
