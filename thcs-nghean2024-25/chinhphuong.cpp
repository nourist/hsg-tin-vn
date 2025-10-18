#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("chinhphuong.INP", "r", stdin);
	freopen("chinhphuong.OUT", "w", stdout);

	ll a, b;
	cin >> a >> b;
	cout << (int)sqrt(b) - (int)sqrt(a) - (sqrt(a) != (int)sqrt(a)) + 1;
	// cout << (ll)sqrt(b) - ceil(sqrt(a))+1;
}
