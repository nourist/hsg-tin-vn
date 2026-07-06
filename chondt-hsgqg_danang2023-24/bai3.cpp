#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

const long long INF = 1e18;

// Hàm Dijkstra tiêu chuẩn
vector<long long> dijkstra(int start, int n, const vector<vector<pair<int, long long>>>& adj) {
	vector<long long> dist(n + 1, INF);
	dist[start] = 0;

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		long long d = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (d > dist[u]) continue;

		for (const auto& edge : adj[u]) {
			int v = edge.first;
			long long w = edge.second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({ dist[v], v });
			}
		}
	}
	return dist;
}

void solve() {
	int n, m, k;
	if (!(cin >> n >> m >> k)) return;

	vector<int> U(k);
	vector<bool> is_U(n + 1, false);
	int k_unique = 0;

	for (int i = 0; i < k; ++i) {
		cin >> U[i];
		if (!is_U[U[i]]) {
			is_U[U[i]] = true;
			k_unique++;
		}
	}

	vector<vector<pair<int, long long>>> adj(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	if (k == 0) {
		cout << "\n";
		return;
	}

	// ---------------------------------------------------------
	// BƯỚC 1: TÌM 2 ĐẦU MÚT A VÀ B
	// ---------------------------------------------------------
	int u1 = U[0];
	vector<long long> dist_u1 = dijkstra(u1, n, adj);

	int A = u1;
	long long max_d = -1;
	for (int u : U) {
		if (dist_u1[u] > max_d && dist_u1[u] != INF) {
			max_d = dist_u1[u];
			A = u;
		}
	}

	vector<long long> dist_A = dijkstra(A, n, adj);

	int B = A;
	max_d = -1;
	for (int u : U) {
		if (dist_A[u] > max_d && dist_A[u] != INF) {
			max_d = dist_A[u];
			B = u;
		}
	}

	vector<long long> dist_B = dijkstra(B, n, adj);
	long long D = dist_A[B];
	if (D == INF) {
		cout << "\n";
		return;
	}

	// ---------------------------------------------------------
	// BƯỚC 2: DP TRÊN DAG SỬ DỤNG THUẬT TOÁN KAHN
	// ---------------------------------------------------------
	vector<bool> on_path(n + 1, false);
	for (int i = 1; i <= n; ++i) {
		if (dist_A[i] + dist_B[i] == D) {
			on_path[i] = true;
		}
	}

	vector<vector<int>> dag_adj(n + 1);
	vector<int> in_degree(n + 1, 0);

	// Dựng đồ thị DAG chỉ chứa các cạnh thuộc đường đi ngắn nhất từ A đến B
	for (int u = 1; u <= n; ++u) {
		if (!on_path[u]) continue;
		for (const auto& edge : adj[u]) {
			int v = edge.first;
			long long w = edge.second;
			// Cạnh u -> v hợp lệ nếu nó kéo dài khoảng cách từ A một đoạn đúng bằng w
			if (on_path[v] && dist_A[u] + w == dist_A[v]) {
				dag_adj[u].push_back(v);
				in_degree[v]++;
			}
		}
	}

	queue<int> q;
	vector<int> dp(n + 1, -1);

	// Đẩy các đỉnh nguồn (bán bậc vào = 0) vào Queue
	for (int i = 1; i <= n; ++i) {
		if (on_path[i] && in_degree[i] == 0) {
			q.push(i);
			if (i == A) dp[i] = 1; // A chắc chắn nằm trong U
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : dag_adj[u]) {
			if (dp[u] != -1) {
				// Cập nhật số lượng điểm nhân chứng tối đa có thể đi qua
				dp[v] = max(dp[v], dp[u] + (is_U[v] ? 1 : 0));
			}
			in_degree[v]--;
			if (in_degree[v] == 0) {
				q.push(v);
			}
		}
	}

	// Nếu hành trình tốt nhất từ A đến B không thu thập đủ số nhân chứng thực tế
	if (dp[B] != k_unique) {
		cout << "\n";
		return;
	}

	// ---------------------------------------------------------
	// BƯỚC 3: TÌM ĐÍCH ĐẾN y
	// ---------------------------------------------------------
	set<int> valid_y;
	for (int y = 1; y <= n; ++y) {
		if (dist_A[y] == INF || dist_B[y] == INF) continue;

		if (dist_A[B] + dist_B[y] == dist_A[y]) {
			valid_y.insert(y);
		}
		else if (dist_B[A] + dist_A[y] == dist_B[y]) {
			valid_y.insert(y);
		}
	}

	cout << valid_y.size() << endl;

	bool first = true;
	for (int y : valid_y) {
		if (!first) cout << " ";
		cout << y;
		first = false;
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}