#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("EXC.inp", "r")) {
		freopen("EXC.inp", "r", stdin);
		freopen("EXC.out", "w", stdout);
	}

	ll n, k, a, res;
	cin >> n >> k;
	res = k * (k + 1) / 2;
	set<ll>st;
	while (n--) {
		cin >> a;
		if(a<=k)
		st.insert(a);
	}
	for (int i : st)res -= i;
	cout << res;
}
