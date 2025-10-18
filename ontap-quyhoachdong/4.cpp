#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll a[(int)1e6 + 100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i <= n; i++) {
		a[i] = (a[i - 1] + a[i - 2]) % ((int)1e9 + 7);
	}
	cout << a[n - 1];
}
//=)) 
//AC plzz
