#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int min_total_difference(vector<int>& a, int k) {
	int n = a.size();
	int fixed_element = a[k - 1];

	vector<int> left(a.begin(), a.begin() + k - 1); 
	vector<int> right(a.begin() + k, a.end());      

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	vector<int> c = left;
	c.push_back(fixed_element);
	c.insert(c.end(), right.begin(), right.end());

	int total_difference = 0;
	for (int i = 0; i < c.size() - 1; ++i) {
		total_difference += abs(c[i + 1] - c[i]);
	}

	return total_difference;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("cau4.inp", "r")) {
		freopen("cau4.inp", "r", stdin);
		freopen("cau4.out", "w", stdout);
	}

	vector<int> a;
	int k, n;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a.push_back(t);
	}

	cout << min_total_difference(a, k);
}
