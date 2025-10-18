#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll d[CHAR_MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	ll l = 0, r = 0, ans = 1;
	for (r; r < str.size(); r++) {
		d[str[r]]++;
		if (d[str[r]] == 1) {
			ans = max(ans, r - l + 1);
			continue;
		}

		while (d[str[r]] != 1) {
			d[str[l]]--;
			l++;
		}
	}
	cout << ans;
}
//=)) 
//AC plzz
