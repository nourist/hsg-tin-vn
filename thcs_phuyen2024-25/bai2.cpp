#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai2.inp", "r")) {
		freopen("bai2.inp", "r", stdin);
		freopen("bai2.out", "w", stdout);
	}

	string str;
	cin >> str;
	deque<char>d;
	for (int i = 0; i < str.size(); i++) {
		if (i % 2 == 0) {
			d.push_front(str[i]);
		}
		else {
			d.push_back(str[i]);
		}
	}
	while (!d.empty()) {
		if (str.size() % 2 == 1) {
			cout << d.front();
			d.pop_front();
		}
		else {
			cout << d.back();
			d.pop_back();
		}
	}
}
