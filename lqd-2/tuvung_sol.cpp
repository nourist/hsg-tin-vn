#include <bits/stdc++.h>
using namespace std;

#define N 1000002
const char nguyenam[] = { 'a', 'e', 'i', 'o', 'u' };
string s;
int cnt[2][N];
long long res[2];

bool check_nguyenam(char x) {
	for (auto k : nguyenam)
		if (k == x) return true;
	return false;
}

int main() {
	freopen("TUVUNG.INP", "r", stdin);
	freopen("TUVUNG.OUT", "w", stdout);

	cin >> s;

	if (check_nguyenam(s[0])) cnt[0][0] = 1;
	else cnt[1][0] = 1;

	for (int i = 1; i < s.size(); i++) {
		if (check_nguyenam(s[i])) {
			res[0] += cnt[1][i - 1];
			cnt[0][i] = cnt[0][i - 1] + 1;
			cnt[1][i] = cnt[1][i - 1];
		}
		else {
			res[1] += cnt[0][i - 1];
			cnt[0][i] = cnt[0][i - 1];
			cnt[1][i] = cnt[1][i - 1] + 1;
		}
	}

	cout << res[0] + res[1] << endl;
	return 0;
}
