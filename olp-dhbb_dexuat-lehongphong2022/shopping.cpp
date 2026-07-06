#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define X first 
#define Y second 

int n;
int a[(int)5e4 + 4], b[(int)5e4 + 4];
int lenA[(int)5e4 + 4], lenB[(int)5e4 + 4];
int l[(int)5e4 + 4], r[(int)5e4 + 4];

void calcLen(int arr[], int len[]) {
	memset(l, 0, sizeof l);
	memset(r, 0, sizeof r);

	stack<int>st;
	FOR(i, 1, n) {
		while (!st.empty() && arr[st.top()] > arr[i]) {
			r[st.top()] = i;
			st.pop();
		}

		st.push(i);
	}

	while (!st.empty()) {
		r[st.top()] = n + 1;
		st.pop();
	}

	FOD(i, n, 1) {
		while (!st.empty() && arr[st.top()] > arr[i]) {
			l[st.top()] = i;
			st.pop();
		}

		st.push(i);
	}

	FOR(i, 1, n)len[i] = r[i] - l[i] - 1;
}

ll solve(vector<pii>a, vector<pii>b) {
	sort(a.begin(), a.end(), greater<pii>());
	sort(b.begin(), b.end(), greater<pii>());

	ll res = 0, len = 0, idx = 0;

	FOR(i, 0, n - 1) {
		while (idx < n && b[idx].X >= a[i].X) {
			len = max(len, (ll)b[idx].Y);
			idx++;
		}

		res = max(res, len * a[i].Y * a[i].X);
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("shopping.inp", "r")) {
		freopen("shopping.inp", "r", stdin);
		freopen("shopping.out", "w", stdout);
	}

	cin >> n;

	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)cin >> b[i];

	calcLen(a, lenA);
	calcLen(b, lenB);

	vector<pii>ar, br;

	FOR(i, 1, n) {
		ar.push_back({ a[i], lenA[i] });
		br.push_back({ b[i], lenB[i] });
	}

	cout << max(solve(ar, br), solve(br, ar));
}

/*
row: a: l,r
col: b: u,v

h = min(min(al...ar), min(bu...bv))

s = (v-u+1)*(r-l+1)*h

*/