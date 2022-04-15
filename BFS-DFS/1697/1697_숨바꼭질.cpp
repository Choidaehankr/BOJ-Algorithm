#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N = 0, K;
bool visited[200000];

int solution(int cur, int dest) {
	queue<pair<int, int>> q;
	q.push(make_pair(cur, 0));
	visited[cur] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int mv[3] = { -1, 1, x};
		int count = q.front().second;
		if (dest == x) {
			return count;
		}
		q.pop();
		for (int i = 0; i < 3; i++) {
			int nx = x + mv[i];
			if (nx < 0 || visited[nx] || nx > 100000) continue;
			q.push(make_pair(nx, count + 1));
			visited[nx] = true;
		}
	}
}

int main() {
	cin >> N >> K;
	cout << solution(N, K);
}