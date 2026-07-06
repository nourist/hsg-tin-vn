#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n, k;
	string s;
	cin >> n >> k >> s;
	sort(s.begin(), s.end());
	for (long long i = 0; i < k; ++i) {
		cout << s[i * (n / k) + min(i, n % k)];
	}
	return 0;
}