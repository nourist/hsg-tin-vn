#include <bits/stdc++.h>
using namespace std;

const int MAX = 10005;

int M, N;
int p[MAX], match_[MAX];
int a[105][105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N;
	int K = 2 * (M + N);

	for (int i = 1; i <= K; i++) {
		cin >> p[i];
		match_[i] = p[i];
	}

	// deque lưu vòng lỗ
	deque<int> dq;
	for (int i = 1; i <= K; i++) dq.push_back(i);

	int top = 1, bottom = M;
	int left = 1, right = N;

	auto solve_cell = [&](int i, int j) {
		int u = dq[0];
		int v = dq[1];

		if (match_[u] == v) {
			a[i][j] = 1; // có gương
		}
		else {
			a[i][j] = 0; // không gương
			int x = match_[u];
			int y = match_[v];
			match_[x] = y;
			match_[y] = x;
		}

		dq.pop_front();
		dq.pop_front();
		};

	while (top <= bottom && left <= right) {

		// 1. cột trái ↓
		for (int i = top; i <= bottom; i++) {
			solve_cell(i, left);
		}
		left++;
		if (left > right) break;

		// 2. hàng dưới →
		for (int j = left; j <= right; j++) {
			solve_cell(bottom, j);
		}
		bottom--;
		if (top > bottom) break;

		// 3. cột phải ↑
		for (int i = bottom; i >= top; i--) {
			solve_cell(i, right);
		}
		right--;
		if (left > right) break;

		// 4. hàng trên ←
		for (int j = right; j >= left; j--) {
			solve_cell(top, j);
		}
		top++;
	}

	// in kết quả
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}