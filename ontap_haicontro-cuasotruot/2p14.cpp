#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e3 * 2 + 8];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a, a + n);

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			ans += lower_bound(a + j + 1, a + n, a[i] + a[j]) - a - j - 1;
		}
	}
	cout << ans;
}

//=)) 
//AC plzz
