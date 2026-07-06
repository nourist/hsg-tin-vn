#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

pair<int,int>winer(vector<pair<int,int>>a) {
	sort(a.begin(), a.end(), [&](pair<int, int>x, pair<int, int>y) {
		if (x.second != y.second)return x.second > y.second;
		else return x.first > y.first;
		});
	return { a[0].first, a[0].second + a[1].second };
}

pair<int, int>solve(vector<pair<int, int>>a) {
	if (a.size() == 1)return a[0];
	vector<pair<int, int>>newA;
	if (a.size() % 2 == 0) {
		for (int i = 0; i < a.size(); i += 2) {
			newA.push_back(winer({ a[i], a[i + 1] }));
		}
	}
	else {
		for (int i = 0; i < a.size() ; i += 2) {
			if (a.size() - i == 3) {
				newA.push_back(winer({ a[i], a[i + 1], a[i + 2] }));
				break;
			}
			else
			newA.push_back(winer({ a[i], a[i + 1] }));
		}
	}
	return solve(newA);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("doikhang.inp", "r")) {
		freopen("doikhang.inp", "r", stdin);
		freopen("doikhang.out", "w", stdout);
	}

	int n;
	cin >> n;
	vector<pair<int,int>>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].second;
		a[i].first = i+1;
	}
	pair<int, int>res = solve(a);
	cout<<res.first<<"\n"<<res.second;
}
