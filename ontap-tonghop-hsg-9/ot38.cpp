#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll d[CHAR_MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("STRLONG.INP", "r", stdin);
	freopen("STRLONG.OUT", "w", stdout);

	ll n;
	string str;
	cin >> n >> str;
	ll l = 0, r = 0, res = 0;
	while (r < n) {
		d[str[r]]++;
		while (d[str[r]] > 1) {
			res += n - r;
			d[str[l++]]--;
		}
		r++;
	}
	cout << res;
}
