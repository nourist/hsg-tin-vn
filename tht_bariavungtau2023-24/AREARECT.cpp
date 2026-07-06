#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("AREARECT.inp", "r")) {
		freopen("AREARECT.inp", "r", stdin);
		freopen("AREARECT.out", "w", stdout);
	}

	ll n, a, b, c, d, x1=-1e9, x2=1e9, y1=-1e9, y2=1e9;
	cin >> n;
	while(n--) {
		cin >> a >> b >> c >> d;
		x1 = max(x1, a);
		y1 = max(y1, b);
		x2 = min(x2, c);
		y2 = min(y2, d);
	}
	cout<<max(0LL,x2-x1)*max(0LL,y2-y1);
}
