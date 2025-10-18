#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a, b;
	cin >> a >> b;
	if (a % 2 == 0)a++;
	if (b % 2 == 0)b--;
	cout << ((b - a) / 2 + 1) * (b + a) / 2;
	return 0;
}
