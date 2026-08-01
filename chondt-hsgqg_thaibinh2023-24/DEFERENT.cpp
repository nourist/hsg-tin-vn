#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); ++i)
#define FOD(i,r,l) for (int i = (r); i >= (l); --i)
#define ll long long
#define db double
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define endl '\n'
#define BIT(x, i) (((x) >> (i)) & 1)
#define BIT_COUNT(x) __builtin_popcountll(x)
#define LOWEST_BIT(x) __builtin_ctzll(x)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "DEFERENT"

int a[(int)4e5 + 5];
int lMax[(int)4e5 + 5];
int rMax[(int)4e5 + 5];
int lMin[(int)4e5 + 5];
int rMin[(int)4e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> a[i];

	stack<int>st;
	FOR(i, 1, n) {
		while (!st.empty() && a[st.top()] < a[i]) {
			rMax[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		rMax[st.top()] = n + 1;
		st.pop();
	}
	FOD(i, n, 1) {
		while (!st.empty() && a[st.top()] <= a[i]) {
			lMax[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty())st.pop();
	FOR(i, 1, n) {
		while (!st.empty() && a[st.top()] > a[i]) {
			rMin[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		rMin[st.top()] = n + 1;
		st.pop();
	}
	FOD(i, n, 1) {
		while (!st.empty() && a[st.top()] >= a[i]) {
			lMin[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty())st.pop();

	ll res = 0;
	FOR(i, 1, n) {
		res += 1LL * (rMax[i] - i) * (i - lMax[i]) * a[i];
		res -= 1LL * (rMin[i] - i) * (i - lMin[i]) * a[i];
	}
	cout << res;
}
