#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	cout << max(stoll(a), stoll(b));
}
