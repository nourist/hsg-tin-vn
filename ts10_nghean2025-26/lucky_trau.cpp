#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("lucky.inp", "r")) {
		freopen("lucky.inp", "r", stdin);
		freopen("lucky.ans", "w", stdout);
	}

	string str;
	cin >> str;
	vector < pair<int, int>>res;
	FOR(i, 0, str.size() - 1) {
		FOR(j, i, str.size() - 1) {
			int s = 0;
			FOR(k, i, j)
				s = (s * 10 + str[k] - '0') % 291;
			if (s == 0) {
				res.push_back({i+1, j+1});
			}
		}
	}
	cout << res.size();
	for (auto x : res)cerr << x.first << ' ' << x.second << endl;
}