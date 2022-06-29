#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 100

using namespace std;

int dist[101][101];  // 부순 벽들 (가중치, 1 또는 0)
int maze[101][101];
int n, m;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

void solution() {
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	dist[0][0] = 0;
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + mv[i][0];
			int ny = y + mv[i][1];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			// 접근할 곳이 벽이라면
			if (maze[nx][ny] == 1) {
				// (현재까지 부순 벽 + 1), (dist[nx][ny]까지 이전 방문 시 부순 벽) 중 최소값으로 갱신해줌
				if (dist[nx][ny] > dist[x][y] + 1) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
			// 벽이 아니라면 비용이 발생하지 않음
			else if (maze[nx][ny] == 0) {
				if (dist[nx][ny] > dist[x][y]) {
					dist[nx][ny] = dist[x][y];
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	cin >> n >> m; 
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			maze[i][j] = c - '0';
			dist[i][j] = INF;  // 무한대로 초기화
		}
	}
	solution();
	cout << dist[m - 1][n - 1];
}