#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau1.inp", "r")) {
		freopen("cau1.inp", "r", stdin);
		freopen("cau1.out", "w", stdout);
	}

	ll n,a,b;
	cin >> n >> a >> b;
	#define lcm(a,b) (a/__gcd(a,b)*b)
	cout << n / a + n / b - n / lcm(a,b)*2;
}
