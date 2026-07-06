#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define X first 
#define Y second
#define endl '\n'

string a[102];
string b[102];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("BOARD.inp", "r")) {
		freopen("BOARD.inp", "r", stdin);
		freopen("BOARD.out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;

	FOR(i, 1, n) {
		cin >> a[i];
		a[i] = "_" + a[i];
	}
	FOR(i, 1, n) {
		cin >> b[i];
		b[i] = "_" + b[i];
	}

	vector<pii>res;
	FOR(i, 1, n)FOR(j, 1, m) {
		if (a[i][j] == b[i][j])continue;
		else {
			if (i == n || j == m) {
				cout << "NO";
				return 0;
			}
			else {
				res.push_back({ i,j });
				FOR(x, i, i + 1)FOR(y, j, j + 1) {
					if (a[x][y] == 'W')a[x][y] = 'B';
					else a[x][y] = 'W';
				}
			}
		}
	}

	cout << "YES" << endl << res.size() << endl;
	for (auto i : res)cout << i.X << ' ' << i.Y << endl;
}
