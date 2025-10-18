#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll d[CHAR_MAX];

ll enoughtChar(string str) {
	set<ll>st;
	for (ll i = 0; i < str.size(); i++) {
		st.insert(str[i]);
	}
	return st.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	ll cnt = 0, ans = str.size(), l = 0, r = 0, n = enoughtChar(str);

	for (r; r < str.size(); r++) {
		d[str[r]]++;
		if (d[str[r]] == 1)cnt++;
		while (cnt == n) {
			ans = min(ans, r - l + 1);
			if (d[str[l]] == 1)cnt--;
			d[str[l]]--;
			l++;
		}
	}
	cout << ans;
}
//=)) 
//AC plzz
