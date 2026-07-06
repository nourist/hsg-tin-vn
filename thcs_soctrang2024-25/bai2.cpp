#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	string a, b;
	getline(cin, a);
	getline(cin, b);
	ll same = 0;
	for (int i = 0; i < a.size(); i += 2) {
		same += a[i] == b[i];
	}
	ld res = (ld)same / ((a.size() + 1) / 2) * 100;
	cout << fixed << setprecision(2) << res<<endl<<(res>50?"OK":"NO");
}
