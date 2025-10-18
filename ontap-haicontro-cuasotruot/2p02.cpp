#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int limit = 1e7;
int a[limit + 100], b[limit + 100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];

	int cnt = 0, i = 0, j = 0;
	while (j < m) {
		while (i < n && a[i] < b[j]) {
			cnt++;
			i++;
		}
		cout << cnt << " ";
		j++;
	}
}

//=)) 
//AC plzz
