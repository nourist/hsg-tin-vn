#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool d[CHAR_MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	string str;
	cin >> str;
	for (int i : str)d[i] = 1;
	for (int i = 'A'; i <= 'Z'; i++) {
		if (!d[i])cout << (char)i;
	}
}
