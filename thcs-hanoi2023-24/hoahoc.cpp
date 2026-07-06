#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("hoahoc.inp", "r")) {
		freopen("hoahoc.inp", "r", stdin);
		freopen("hoahoc.out", "w", stdout);
	}

	ll a,b;
	cin>>a>>b;
	cout << min(a / 3, b / 2);
}
