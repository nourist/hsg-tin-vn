#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai1.inp", "r")) {
		freopen("bai1.inp", "r", stdin);
		freopen("bai1.out", "w", stdout);
	}

	int n;
	string str;
	cin >> n >> str;

	int res = 0;
	for (auto i : str) {
		if (i != 'u' && i != 'e' && i != 'o' && i != 'a' && i != 'i' && !(i >= '0' && i <= '9'))res++;
	}
	cout << res;
}
