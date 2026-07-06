#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int numChar;
bool ok[16][16];
string str;
int n;

int nextC[110][16];
ll dp[1 << 16][110];

void init() {
	cin >> numChar;
	for(int i = 0; i < numChar; i++) {
		for (int j = 0; j < numChar; j++) {
			cin>> ok[i][j];
		}
	}
	cin >> str;
	n = str.size();
	str = " " + str;
}

void preprocess() {
	for(int j = 0; j < numChar; j++) {
		nextC[n][j] = n + 1;
	}
	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < numChar; j++) {
			if (str[i+1] == j + 'a' || str[i+1] == '*') {
				nextC[i][j] = i + 1;
			} else {
				nextC[i][j] = nextC[i + 1][j];
			}
		}
	}
}

void solve() {
	dp[0][0] = 1;
	for (int mask = 0; mask < (1 << numChar); mask++) {
		for (int pos = 0; pos <= n; pos++) {
			if (dp[mask][pos] == 0) continue;

			for (int c = 0; c < numChar; c++) {
				if(mask & (1 << c)) continue;

				int count = __builtin_popcount(mask);
				if(!ok[c][count]) continue;

				if (nextC[pos][c] > n)continue;

				dp[mask|(1<<c)][nextC[pos][c]] += dp[mask][pos];
			}
		}
	}

	ll res = 0;
	for (int i = 0; i <= n; i++) {
		res += dp[(1 << numChar) - 1][i];
	}
	cout << res << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	preprocess();
	solve();
}