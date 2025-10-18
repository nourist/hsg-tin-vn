#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const ll limit = (ll)3e5 + 10;
ll a[limit];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	ll n;
	cin >> n;

	for(int i =0; i < n; i++)cin>>a[i];
	sort(a, a + n);
	cout << max(a[n-1]*a[n-2]*a[n-3], a[0]*a[1]*a[n-1]);
}
