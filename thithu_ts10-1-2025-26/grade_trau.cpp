#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

string str;

int correct() {
	stack<int> st;
	st.push(str[0] - '0');
	for (int i = 1; i < str.size(); i += 2) {
		if (str[i] == '+') {
			st.push(str[i + 1] - '0');
		}
		else {
			int x = st.top();
			st.pop();
			st.push(x * (str[i + 1] - '0'));
		}
	}
	int res = 0;
	while (!st.empty()) {
		res += st.top();
		st.pop();
	}
	return res;
}

unordered_set<int> memo[32][32];

void Try(int l, int r) {
	if (!memo[l][r].empty()) return;

	if (l == r) {
		memo[l][r].insert(str[l] - '0');
		return;
	}

	for (int i = l + 1; i <= r; i += 2) {
		Try(l, i - 1);
		Try(i + 1, r);
		for (int x : memo[l][i - 1]) {
			for (int y : memo[i + 1][r]) {
				int val = (str[i] == '*') ? x * y : x + y;
				if (val <= 1000) memo[l][r].insert(val);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("grade.inp", "r")) {
		freopen("grade.inp", "r", stdin);
		freopen("grade.ans", "w", stdout);
	}

	cin >> str;
	Try(0, str.size() - 1);
	int n, a, b, x, res = 0;
	int correctValue = correct();
	cin >> n >> a >> b;
	while (n--) {
		cin >> x;
		if (x == correctValue) res += a;
		else if (memo[0][str.size() - 1].count(x)) res += b;
	}
	cout << res;
}
