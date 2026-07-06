#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("cau1.inp", "r")) {
		freopen("cau1.inp", "r", stdin);
		freopen("cau1.out", "w", stdout);
	}

	string str;
	cin >> str;
	int x = 0, y = 0;
	for (char ch : str) {
		if (ch == 'E')x++;
		if (ch == 'S')y--;
		if (ch == 'W')x--;
		if (ch == 'N')y++;
	}
	cout << x << ' ' << y;
}
