#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int n;
int a[(int)1e5 + 5];
int f[(int)1e5 + 5];
int cnt = 0;

void clear() {
	cnt = 0;
	for (int i = 0; i <= 1e5; i++)f[i] = 0;
}

void add(int x) {
	if (f[x] == 0)cnt++;
	f[x]++;
}

void remove(int x) {
	if (f[x] == 1)cnt--;
	f[x]--;
}

int twoPointer(int k) {
	clear();
	int l = 0, r = 0, res =0;
	while (r < n) {
		add(a[r]);
		while (cnt > k) {
			remove(a[l++]);
		}
		res += r - l + 1;
		r++;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bai4.inp", "r")) {
		freopen("bai4.inp", "r", stdin);
		freopen("bai4.out", "w", stdout);
	}

	int k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> a[i];

	cout << twoPointer(k) - twoPointer(k - 1);
}