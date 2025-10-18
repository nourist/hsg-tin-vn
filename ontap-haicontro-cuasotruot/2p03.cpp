#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int limit = 1e7;
int a[limit + 100], b[limit + 100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];
	ll ans = 0;
	int i = 0, j = 0;

	while (i < n && j < m) {
		if (a[i] < b[j]) {
			i++;
			continue;
		}
		else if (a[i] > b[j]) {
			j++;
			continue;
		}

		int cnt1 = 0, cnt2 = 0;
		while (i < n && a[i] == b[j]) {
			cnt1++;
			i++;
		}

		int tmp = a[i - 1];
		while (j < m && tmp == b[j]) {
			cnt2++;
			j++;
		}
		ans += (1ll * cnt1 * cnt2);
	}
	cout << ans;
}

//=)) 
//AC plzz
