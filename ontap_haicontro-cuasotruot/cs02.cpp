#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int a[(int)1e6 + 8];
multiset<int>d;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < k; i++) {
		d.insert(a[i]);
	}
	cout << *d.begin() << " " << *d.rbegin() << endl;
	for (int i = k; i < n; i++) {
		d.insert(a[i]);
		d.erase(d.find(a[i - k]));
		cout << *d.begin() << " " << *d.rbegin() << endl;
	}
}
//=)) 
//AC plzz
