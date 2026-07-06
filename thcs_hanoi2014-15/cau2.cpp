#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau2.inp", "r")) {
		freopen("cau2.inp", "r", stdin);
		freopen("cau2.out", "w", stdout);
	}

	int n, h;
	cin >> n >> h;

	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	ll start = 0, cnt =0;
	for (int i = 0; i < n; i++) {
		if (a[i] - a[start] > h) {
			cnt++;
			start = i;
		}
	}
	cnt++;
	cout << cnt;
}
