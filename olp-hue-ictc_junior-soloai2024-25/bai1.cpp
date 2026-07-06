#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin>>n;

	ll a = (n - 1) / 2;

	const ll mod = 1e9 + 7;
	cout << (a * (a + 1) % mod + ((n - 1) / 2 + 1) % mod) % mod;
	//1+3+5...+n
	//n+0+2+4+...(n-1)
	//n+
}
