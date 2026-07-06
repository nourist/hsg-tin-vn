#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

typedef long long ll;

ll countDivisibleSubstrings(const string& s) {
	const int MOD = 291;
	unordered_map<int, ll> freq;
	freq[0] = 1; // Tính cho các đoạn bắt đầu từ đầu
	ll cur = 0, result = 0;

	for (char ch : s) {
		cur = (cur * 10 + (ch - '0')) % MOD;
		result += freq[cur];
		freq[cur]++;
	}

	return result;
}

int main() {
	string s;
	cin >> s;
	cout << countDivisibleSubstrings(s) << '\n';
	return 0;
}
