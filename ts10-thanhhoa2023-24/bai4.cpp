#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int d[CHAR_MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	string str;
	cin >> str;
	for (int i : str)d[i]++;
	ll res = str.size() * (str.size() - 1) / 2 + 1;
	for (int i = 'a'; i <= 'z'; i++)res -= d[i] * (d[i] - 1) / 2;
	cout << res;
}
