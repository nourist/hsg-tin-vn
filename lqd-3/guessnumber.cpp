#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int p[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("guessnumber.inp", "r")) {
		freopen("guessnumber.inp", "r", stdin);
		freopen("guessnumber.out", "w", stdout);
	}

	for (int i = 1; i <= 1e5; i++) {
		p[i] = i;
	}
	for(int i = 2; i*i <= 1e5; i++) {
		if (p[i] != i) continue;
		for (int j = i * i; j <= 1e5; j += i) {
			p[j] = min(p[j], i);
		}
	}

	int n;
	cin >> n;

	set<int>s;
	s.insert(1);
	for (int i = 1; i <= n; i++) {
		int x = i;
		while (x != 1) {
			s.insert(p[x]);
			x /= p[x];
		}
	}
	cout << s.size() << "\n";
}

/*

4
1 2 3 4
1 2 3 2

1 2 3 4 5
1 2 3 2 5

1 2 3 4 5 6
1 2 3 2 5 2-3

*/