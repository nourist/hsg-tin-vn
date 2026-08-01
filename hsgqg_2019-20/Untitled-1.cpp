#include <bits/stdc++.h>
using namespace std;

// Solution by Hồ Đình Vỹ

const long long INF = 2e18;

// Cấu trúc lưu trữ cạnh đồ thị
struct Edge {
	int u, v;
	long long w;
	bool operator<(const Edge& other) const {
		return w < other.w;
	}
};

// Cấu trúc Rollback DSU chỉ sử dụng Gộp theo kích thước (Union by Size)
struct RollbackDSU {
	vector<int> parent, sz;
	// Lịch sử lưu trữ: {đỉnh con, đỉnh cha, kích thước cũ của đỉnh con}
	vector<tuple<int, int, int>> history;

	RollbackDSU(int n) {
		parent.resize(n + 1);
		sz.assign(n + 1, 1);
		iota(parent.begin(), parent.end(), 0);
	}

	// KHÔNG dùng Path Compression để bảo toàn cấu trúc cây cho việc undo
	int find(int i) {
		while (i != parent[i]) i = parent[i];
		return i;
	}

	bool unite(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return false;

		// Luôn gắn cây nhỏ vào cây lớn
		if (sz[u] < sz[v]) swap(u, v);

		// Lưu lại lịch sử trước khi gộp: v chuẩn bị được gắn vào u
		history.push_back({ v, u, sz[v] });
		parent[v] = u;
		sz[u] += sz[v];
		return true;
	}

	int get_state() {
		return history.size();
	}

	void rollback_to(int state) {
		while (history.size() > state) {
			auto [v, u, sz_v] = history.back();
			history.pop_back();
			parent[v] = v;
			sz[u] -= sz_v;
		}
	}

	bool connected(int u, int v) {
		return find(u) == find(v);
	}
};

int n, m, S, T;
vector<Edge> A, B;
long long ans = INF;
RollbackDSU* dsu;

// Hàm chia để trị
void solve(int l, int r, int opt_l, int opt_r) {
	if (l > r) return;
	int mid = l + (r - l) / 2;

	int state_start = dsu->get_state();

	// Bước 1: Thêm các cạnh của A từ l đến mid
	for (int i = l; i <= mid; ++i) {
		dsu->unite(A[i].u, A[i].v);
	}

	int state_after_A = dsu->get_state();
	int opt_mid = -1;

	// Bước 2: Thử nghiệm thêm dần các cạnh của B
	for (int k = opt_l; k <= opt_r; ++k) {
		dsu->unite(B[k].u, B[k].v);
		if (dsu->connected(S, T)) {
			opt_mid = k;
			ans = min(ans, A[mid].w + B[k].w);
			break;
		}
	}

	// Cắt tỉa: Nếu dùng hết cạnh B đến opt_r mà vẫn chưa liên thông được S và T
	// => Cần thêm cạnh A (tìm ở nửa phải). Không thể tìm ở nửa trái.
	if (opt_mid == -1) {
		dsu->rollback_to(state_after_A);
		solve(mid + 1, r, opt_l, opt_r);
		dsu->rollback_to(state_start);
		return;
	}

	// Trả lại mặt bằng trạng thái DSU ban đầu (Rollback)
	dsu->rollback_to(state_start);

	// Bước 3: Đệ quy nửa trái [l, mid - 1]
	for (int k = opt_l; k < opt_mid; ++k) {
		dsu->unite(B[k].u, B[k].v);
	}
	solve(l, mid - 1, opt_mid, opt_r);
	dsu->rollback_to(state_start);

	// Bước 4: Đệ quy nửa phải [mid + 1, r]
	for (int i = l; i <= mid; ++i) {
		dsu->unite(A[i].u, A[i].v);
	}
	solve(mid + 1, r, opt_l, opt_mid);
	dsu->rollback_to(state_start);
}

int main() {
	// Tối ưu hóa I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	if (!(cin >> n >> m >> S >> T)) return 0;

	// Kỹ thuật Dummy Edge: Xử lý mượt mà trường hợp Alice 
	// chỉ đi toàn xe của một công ty mà không cần viết lệnh if/else dài dòng.
	A.push_back({ S, S, 0 });
	B.push_back({ S, S, 0 });

	for (int i = 0; i < m; ++i) {
		int u, v;
		long long w;
		int company;
		// Tùy theo format đề bài, thứ tự đọc có thể điều chỉnh lại ở đây
		cin >> company >> u >> v >> w;

		if (company == 1) A.push_back({ u, v, w });
		else B.push_back({ u, v, w });
	}

	// Sắp xếp các tuyến xe của mỗi công ty tăng dần theo giá vé
	// Bỏ qua index 0 vì nó là Dummy Edge
	if (A.size() > 1) sort(A.begin() + 1, A.end());
	if (B.size() > 1) sort(B.begin() + 1, B.end());

	dsu = new RollbackDSU(n);

	// Gọi hàm D&C
	solve(0, A.size() - 1, 0, B.size() - 1);

	if (ans >= INF) cout << -1 << "\n";
	else cout << ans << "\n";

	delete dsu;
	return 0;
}