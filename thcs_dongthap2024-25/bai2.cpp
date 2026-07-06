#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

bool p[(int)1e6 + 6];

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(NULL);
	cin.tie(NULL);

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 1e6; i++)
		if (p[i])
			for (int j = i * i; j <= 1e6; j += i)p[j] = 0;

	int n, res = -1, x;
	cin >> n;
	while (n--) {
		cin >> x;
		if (x > 1 && p[x])res = max(res, x);
	}
	cout << res;
}
