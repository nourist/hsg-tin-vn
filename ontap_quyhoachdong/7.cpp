#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[300];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sum = accumulate(a, a + n, 0);
	for (int i = 0; i < n; i++) {
		if (a[i] == sum - a[i]) {
			cout << a[i];
			return 0;
		}
	}
	cout << "N";
}
//=)) 
//AC plzz
