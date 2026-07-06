#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e6 + 8], median = INT_MAX, k;
multiset<int>low, high;

void ins(int val) {
	if (val <= median) {
		low.insert(val);
		median = *low.rbegin();

		if (low.size() > (k + 1) / 2) {
			high.insert(*low.rbegin());
			auto it = low.end();
			it--;
			low.erase(it);
		}
	}
	else {
		high.insert(val);

		if (high.size() > k / 2) {
			low.insert(*high.begin());
			high.erase(high.begin());
		}
	}
}

void era(int val) {
	if (low.find(val) != low.end()) {
		low.erase(low.find(val));

		if (high.size() > k / 2) {
			low.insert(*high.begin());
			high.erase(high.begin());
		}
	}
	else {
		high.erase(high.find(val));

		if (low.size() > (k + 1) / 2) {
			high.insert(*low.rbegin());
			auto it = low.end();
			it--;
			low.erase(it);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < k; i++) {
		ins(a[i]);
		median = *low.rbegin();
	}
	cout << median << " ";
	for (int i = k; i < n; i++) {
		era(a[i - k]);
		ins(a[i]);
		median = *low.rbegin();
		cout << median << " ";
	}
}
//=)) 
//AC plzz
