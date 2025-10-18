#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, q;
	cin >> n >> k >> q;

	vector<pair<int, int>>v;

	for (int x,y, i = 1; i <= k; ++i) {
		cin >> x >> y;
		v.push_back({ x,1 });
		v.push_back({ y+1,-1 });
	}

	v.push_back({ 0,0 });
	sort(v.begin(), v.end());
	for (int i = 1; i <= v.size(); ++i) {
		v[i].second += v[i - 1].second;
	}

	for (int x, i = 1; i <= q; ++i) {
		cin >> x;
		cout << (--upper_bound(v.begin(), v.end(), make_pair(x, (int)1e9)))->second << '\n';
	}
}