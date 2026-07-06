#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

struct Edge {
	int u, v, day;
};

struct Query {
	int a, b, id;
	int l, r, ans;
};

int N, M, Q;
vector<Edge> edges;
vector<Query> queries;
vector<int> days; // ngày hoàn thành thực tế
unordered_map<int, vector<int>> day_to_queries; // gom truy vấn theo mid

// DSU
vector<int> parent;

void init_dsu(int n) {
	parent.resize(n);
	iota(parent.begin(), parent.end(), 0);
}

int find(int u) {
	return (u == parent[u]) ? u : parent[u] = find(parent[u]);
}

void unite(int u, int v) {
	u = find(u), v = find(v);
	if (u != v) parent[v] = u;
}

int get_day_index(int d) {
	return lower_bound(days.begin(), days.end(), d) - days.begin();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> Q;
	edges.resize(M);
	for (int i = 0; i < M; ++i) {
		cin >> edges[i].u >> edges[i].v >> edges[i].day;
		--edges[i].u; --edges[i].v;
		days.push_back(edges[i].day);
	}

	// Lấy danh sách ngày duy nhất và sắp xếp
	sort(days.begin(), days.end());
	days.erase(unique(days.begin(), days.end()), days.end());

	queries.resize(Q);
	for (int i = 0; i < Q; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		queries[i] = { a, b, i, 0, (int)days.size() - 1, -1 };
		if (a == b) {
			queries[i].ans = 0;
			queries[i].l = queries[i].r = -1;
		}
	}

	vector<int> answer(Q, -1);

	while (true) {
		day_to_queries.clear();
		bool has_query = false;

		for (auto& q : queries) {
			if (q.ans != -1 || q.l > q.r) continue;
			has_query = true;
			int mid = (q.l + q.r) / 2;
			day_to_queries[mid].push_back(q.id);
		}

		if (!has_query) break;

		// DSU khởi tạo lại
		init_dsu(N);
		int edge_idx = 0;

		for (int i = 0; i < (int)days.size(); ++i) {
			// Thêm các cạnh có ngày <= days[i]
			while (edge_idx < M && edges[edge_idx].day <= days[i]) {
				unite(edges[edge_idx].u, edges[edge_idx].v);
				edge_idx++;
			}

			// Xử lý các truy vấn cần check ở ngày days[i]
			for (int id : day_to_queries[i]) {
				auto& q = queries[id];
				if (find(q.a) == find(q.b)) {
					q.ans = days[i];
					q.r = i - 1;
				}
				else {
					q.l = i + 1;
				}
			}
		}
	}

	// Xuất kết quả
	for (auto& q : queries)
		cout << q.ans << '\n';

	return 0;
}
