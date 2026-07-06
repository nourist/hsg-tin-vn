#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("AIRPORT.inp", "r")) {
		freopen("AIRPORT.inp", "r", stdin);
		freopen("AIRPORT.out", "w", stdout);
	}

	int n;
	cin >> n;
	vector<pair<int, int>>v;
	for (int a,b, i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,1 });
		v.push_back({ b+1,-1 });
	}
	sort(v.begin(), v.end());
	for(int i = 1; i < v.size(); i++) {
		v[i].second += v[i - 1].second;
	}
	int res = 0;
	for (int i = 0; i < v.size(); i++) {
		res = max(res, v[i].second);
	}
	cout << res;
}
