#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

int m[5][5];
int allowed[5][5];

string str = "000000000";
bool solve(int x, int y, int depth) {
	str[depth] = m[x][y] + '0';
	allowed[x][y] = 0;
	if (depth == 8) return true;

	vector < pair<int, pair<int, int>>>edge;
	if (allowed[x - 1][y]) {
		edge.push_back(make_pair(m[x - 1][y], make_pair(x - 1, y)));
	}
	if (allowed[x + 1][y]) {
		edge.push_back(make_pair(m[x + 1][y], make_pair(x + 1, y)));
	}
	if (allowed[x][y - 1]) {
		edge.push_back(make_pair(m[x][y - 1], make_pair(x, y - 1)));
	}
	if (allowed[x][y + 1]) {
		edge.push_back(make_pair(m[x][y + 1], make_pair(x, y + 1)));
	}
	sort(edge.begin(), edge.end(), greater<pair<int, pair<int, int>>>());
	for (auto e : edge) {
		if (solve(e.second.first, e.second.second, depth + 1)) return true;
	}
	allowed[x][y] = 1;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("khobau.inp", "r")) {
		freopen("khobau.inp", "r", stdin);
		freopen("khobau.out", "w", stdout);
	}

	int t;
	cin >> t;
	while (t--) {
		FOR(i, 1, 3)FOR(j, 1, 3)cin >> m[i][j];
		FOR(i, 1, 3)FOR(j, 1, 3)allowed[i][j] = 1;
		vector < pair<int, pair<int, int>>>v;
		FOR(i, 1, 3)FOR(j, 1, 3) {
			v.push_back(make_pair(m[i][j], make_pair(i, j)));
		}
		sort(v.begin(), v.end(), greater<pair<int, pair<int, int>>>());
		for (auto e : v) {
			if (solve(e.second.first, e.second.second, 0)) break;
		}
		cout << str << endl;
	}
}