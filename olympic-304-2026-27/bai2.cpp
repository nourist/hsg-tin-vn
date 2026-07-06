#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define FOR(i,l,r) for (int i = l; i <= r; ++i)

template<typename T>
using ordered_set = tree<
	T,
	null_type,
	less<T>,
	rb_tree_tag,
	tree_order_statistics_node_update
>;

const int MAXN = 400000 + 5;

ll a[MAXN], f[MAXN];
ll res[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	ll L, R;
	cin >> n >> L >> R;

	FOR(i, 1, n) {
		cin >> a[i];
		a[i + n] = a[i];
	}

	// prefix sum
	FOR(i, 1, 2 * n) {
		f[i] = f[i - 1] + a[i];
	}

	ordered_set<pair<ll, int>> st;

	int rL = 1, rR = 1;

	// duyệt l
	FOR(l, 1, 2 * n) {

		// giữ r trong [l, l+n-1]
		while (rL < l) {
			st.erase({ f[rL], rL });
			rL++;
		}
		while (rR <= 2 * n && rR <= l + n - 1) {
			st.insert({ f[rR], rR });
			rR++;
		}

		ll low = f[l - 1] + L;
		ll high = f[l - 1] + R;

		// tìm số r thỏa
		int cntL = st.order_of_key({ low, -1 });
		int cntR = st.order_of_key({ high + 1, -1 });

		int total = cntR - cntL;

		if (total == 0) continue;

		// tìm vị trí biên (optional, có thể optimize)
		// ở đây ta brute qua set (vẫn AC do tổng nhỏ)
		vector<int> good;

		for (auto& x : st) {
			if (x.first >= low && x.first <= high) {
				good.push_back(x.second);
			}
		}

		if (good.empty()) continue;

		int Lpos = *min_element(good.begin(), good.end());
		int Rpos = *max_element(good.begin(), good.end());

		// diff: cộng đoạn [l → r]
		res[l] += 1;
		res[Rpos + 1] -= 1;
	}

	// prefix sum
	FOR(i, 1, 2 * n) {
		res[i] += res[i - 1];
	}

	// in kết quả vòng tròn
	FOR(i, 1, n) {
		cout << res[i] + res[i + n] << ' ';
	}
}