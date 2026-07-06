#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool ok(string s, string t) {
	int f[255];
	fill(f, f + 255, 0);
	for (int i : t)f[i] = 1;
	for (int i : s) {
		if (!f[i])
			return 0;
	}
	return 1;
}

int nx[(int)1e5 + 5][26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	string s, t;
	cin >> s >> t;

	if (!ok(s, t)) {
		cout << -1;
		return 0;
	}

	s = "_" + s;
	t = "_" + t;

	for (int i = 0; i < 26; i++)nx[t.size()][i] = -1;
	for (int i = t.size() - 1; i >= 1; i--) {
		for (int j = 0; j < 26; j++) {
			if (j + 'a' == t[i]) {
				nx[i][j] = i;
			}
			else {
				nx[i][j] = nx[i + 1][j];
			}
		}
	}

	int pos = 0, cnt = 1;
	for (int i = 1; i < s.size(); i++) {
		int ch = s[i] - 'a';
		if (nx[pos + 1][ch] == -1) {
			pos = 0;
			cnt++;
		}
		pos = nx[pos + 1][ch];
	}
	cout << cnt;
}

//complex solution
//2,501s, 14.86 MB

/*
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool ok(string s, string t) {
	int f[255];
	fill(f, f + 255, 0);
	for (int i : t)f[i] = 1;
	for (int i : s) {
		if (!f[i])
			return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	string s, t;
	cin >> s >> t;

	if (!ok(s,t)) {
		cout << -1;
		return 0;
	}

	string m = t;
	int i = 0, j = 0;
	while (1) {
		while (j < m.size()) {
			if (m[j] == s[i]) {
				i++;
			}
			j++;
		}
		if (i == s.size())break;
		if (j == m.size())m += t;
	}
	cout << m.size() / t.size();
}

*/

//easy solution
//5,709s, 52.21 MB