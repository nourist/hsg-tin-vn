#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxN = 1e5 + 5;

struct Gift {
	int w, s, id;
};

struct Query {
	int m, k, t, id, type;
	int l, r, ans;
};

int n, q;
Gift gifts[maxN];
Query queries[maxN];
int ans[maxN];

// 4 BITs quản lý các loại quà dựa trên thứ tự W_i tăng dần
int bitCntType[maxN], bitSumS[maxN], bitSumWS[maxN], bitSumW[maxN];

void update(int bit[], int idx, int val) {
	for (; idx <= n; idx += idx & -idx) bit[idx] += val;
}

int getSum(int bit[], int idx) {
	int res = 0;
	for (; idx > 0; idx -= idx & -idx) res += bit[idx];
	return res;
}

// Binary Lifting trên BIT tìm vị trí p sao cho tổng số món quà >= K*T
int find_p(int KT, int T) {
	int pos = 0;
	int currentCount = 0;
	for (int i = 1 << 17; i > 0; i >>= 1) {
		int nextPos = pos + i;
		if (nextPos <= n) {
			int countInNext = bitSumS[nextPos] + bitCntType[nextPos] * T;
			if (currentCount + countInNext < KT) {
				pos = nextPos;
				currentCount += countInNext;
			}
		}
	}
	return pos + 1;
}

// Hàm tính tổng khối lượng nhỏ nhất với giá trị T cụ thể
int calculateWeight(int K, int T, int M) {
	int KT = K * T;
	// Kiểm tra tổng số món tối đa có thể lấy với T túi
	if (getSum(bitSumS, n) + getSum(bitCntType, n) * T < KT) return M + 7;

	int p = find_p(KT, T);
	if (p > n) return M + 7;

	int totalW = getSum(bitSumWS, p - 1) + getSum(bitSumW, p - 1) * T;
	int countSoFar = getSum(bitSumS, p - 1) + getSum(bitCntType, p - 1) * T;
	int need = KT - countSoFar;

	return totalW + need * gifts[p].w;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Mở file theo format thi HSG
	if (fopen("gift.inp", "r")) {
		freopen("gift.inp", "r", stdin);
		freopen("gift.out", "w", stdout);
	}

	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> gifts[i].w;
	for (int i = 1; i <= n; i++) cin >> gifts[i].s;

	sort(gifts + 1, gifts + n + 1, [](Gift a, Gift b) {
		return a.w < b.w;
		});

	vector<int> type2Indices;
	for (int i = 1; i <= q; i++) {
		int type; cin >> type;
		if (type == 1) {
			cin >> queries[i].m >> queries[i].k >> queries[i].t;
			queries[i].type = 1;
		}
		else {
			cin >> queries[i].m >> queries[i].k;
			queries[i].type = 2;
			queries[i].l = 0; queries[i].r = 1e9; // Giới hạn T
			queries[i].ans = 0;
			type2Indices.push_back(i);
		}
		queries[i].id = i;
	}

	// Parallel Binary Search
	while (true) {
		vector<pair<int, int>> checkList;
		for (int idx : type2Indices) {
			if (queries[idx].l <= queries[idx].r) {
				checkList.push_back({ (queries[idx].l + queries[idx].r) / 2, idx });
			}
		}

		// Thêm các Query loại 1 vào để xử lý trong cùng 1 lần duyệt BIT
		for (int i = 1; i <= q; i++) {
			if (queries[i].type == 1) checkList.push_back({ queries[i].t, i });
		}

		if (checkList.empty()) break;
		sort(checkList.begin(), checkList.end());

		// Reset BITs
		memset(bitCntType, 0, sizeof bitCntType);
		memset(bitSumS, 0, sizeof bitSumS);
		memset(bitSumWS, 0, sizeof bitSumWS);
		memset(bitSumW, 0, sizeof bitSumW);
		for (int i = 1; i <= n; i++) {
			update(bitCntType, i, 1);
			update(bitSumW, i, gifts[i].w);
		}

		vector<pair<int, int>> sortedS;
		for (int i = 1; i <= n; i++) sortedS.push_back({ gifts[i].s, i });
		sort(sortedS.begin(), sortedS.end());

		int sIdx = 0;
		for (auto& check : checkList) {
			int T = check.first;
			int qid = check.second;

			while (sIdx < n && sortedS[sIdx].first <= T) {
				int pos = sortedS[sIdx].second;
				update(bitCntType, pos, -1);
				update(bitSumW, pos, -gifts[pos].w);
				update(bitSumS, pos, gifts[pos].s);
				update(bitSumWS, pos, gifts[pos].s * gifts[pos].w);
				sIdx++;
			}

			int curW = calculateWeight(queries[qid].k, T, queries[qid].m);
			if (queries[qid].type == 1) {
				ans[qid] = (curW <= queries[qid].m);
			}
			else {
				if (curW <= queries[qid].m) {
					queries[qid].ans = T;
					queries[qid].l = T + 1;
				}
				else {
					queries[qid].r = T - 1;
				}
			}
		}

		// Query loại 1 chỉ cần tính 1 lần, sau đó ta "vô hiệu hóa" để vòng sau không tính lại
		for (int i = 1; i <= q; i++) if (queries[i].type == 1) queries[i].type = 0;

		bool hasType2 = false;
		for (int idx : type2Indices) if (queries[idx].l <= queries[idx].r) hasType2 = true;
		if (!hasType2) break;
	}

	for (int i = 1; i <= q; i++) {
		if (ans[i] != -1) { // Đã xử lý (cả loại 1 và loại 2)
			if (queries[i].type == 0) cout << ans[i] << "\n"; // Kết quả loại 1
			else cout << queries[i].ans << "\n"; // Kết quả loại 2
		}
	}
	return 0;
}