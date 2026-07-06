#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

string str;

int correct() {
	stack<int>st;
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

int incorrect(int mark) {
	vector<pair<int, int>>v;
	v.push_back({ '+', str[0] - '0' });
	for (int i = 1; i < str.size(); i += 2) {
		if (mark & (1 << i / 2)) {
			if (str[i] == '*')
				v.back().second *= str[i + 1] - '0';
			else
				v.back().second += str[i + 1] - '0';
		}
		else {
			v.push_back({ str[i], str[i + 1] - '0' });
		}
	}
	int res = 0;
	for (auto x : v) {
		if (x.first == '+') res += x.second;
		else res *= x.second;
	}
	return res;
}

int correctValue, wrongValue[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("grade.inp", "r")) {
		freopen("grade.inp", "r", stdin);
		freopen("grade.out", "w", stdout);
	}

	cin >> str;
	correctValue = correct();
	int cnt = 0;
	FOR(i, 0, str.size() - 1)cnt += (str[i] == '+' || str[i] == '*');
	FOR(i, 0, (1 << cnt) - 1) {
		int x = incorrect(i);
		if (x <= 1000)wrongValue[x] = 1;
	}

	int n, a, b,x,res=0;
	cin >> n>>a>>b;
	while (n--) {
		cin >> x;
		if (x == correctValue)res += a;
		else if (wrongValue[x])res += b;
	}
	cout << res;
}