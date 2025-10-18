#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define name ""

int a[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)cin >> a[i];

	int mn = *min_element(a + 1, a + n + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++)cnt += a[i] != mn;
	cout << mn << ' ';
	cout << (cnt == 0 ? n : cnt);
}
