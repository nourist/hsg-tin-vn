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

	ll a, b;
	cin >> a >> b;

	vector<ll>res;
	for (int i = 1; i <= a; i++)res.push_back(i);
	int i = 0;
	while(res.size() > 1) {
		i = (i + b - 1) % res.size();
		res.erase(res.begin() + i);
	}
	cout << res[0];
}
