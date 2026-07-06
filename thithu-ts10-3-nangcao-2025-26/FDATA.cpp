#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double

int n, k, a[(int)1e7 + 7];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("FDATA.inp", "r")) {
		freopen("FDATA.inp", "r", stdin);
		freopen("FDATA.out", "w", stdout);
	}

	cin >> n >> k;
	FOR(i, 1, n)cin >> a[i];

	deque<int>qmin, qmax;
	int l = 1, r = 1, res= 1;
	while (r <= n) {
		while(!qmin.empty()&&a[qmin.back()] >= a[r]) qmin.pop_back();
		while (!qmax.empty() && a[qmax.back()] <= a[r]) qmax.pop_back();
		qmax.push_back(r);
		qmin.push_back(r);
		while (a[qmax.front()] * a[qmax.front()] - a[qmin.front()] * a[qmin.front()] > k) {
			l++;
			while(!qmin.empty() && qmin.front() < l) qmin.pop_front();
			while(!qmax.empty() && qmax.front() < l) qmax.pop_front();
		}
		res = max(res, r - l + 1);
		r++;
	}
	cout << res;
}
