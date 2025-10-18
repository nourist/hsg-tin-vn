#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define lcm(a,b) a/__gcd(a,b)*b

string dupstr(int n, string str) {
	string res = "";
	for (int i = 0; i < n; i++)res += str;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("strlcm.INP", "r", stdin);
	freopen("strlcm.OUT", "w", stdout);

	int t;
	string a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int res = lcm(a.size(), b.size());
		string s1 = dupstr(res / a.size(), a);
		string s2 = dupstr(res / b.size(), b);
		if (s1 == s2)cout << s1 << endl;
		else cout << -1 << endl;
	}
}
