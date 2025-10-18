#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e5 + 8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	unordered_map<int, int>mp;

	int res = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] -= k;
		a[i] += a[i - 1];
		if (a[i] == 0)res++;
		res += mp[a[i]]++;
	}
	cout << res;
}
