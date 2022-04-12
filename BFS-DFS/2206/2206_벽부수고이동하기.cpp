#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m;
int map[1000][1000];
int visited[1000][1000][2];

int bfs() {
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(0, 0), 1));
	// visited[x][y][0]: 벽을 부순 상태에서 x,y까지 이동한 거리
	// visited[x][y][1]: 벽을 부수지 않은 상태에서 x,y까지 이동한 거리

	visited[0][0][1] = 1; // 부수지 않은 상태로 시작
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int flag = q.front().second;
		q.pop();
		if (x == n - 1 && y == m - 1) {
			return visited[x][y][flag];
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				// 벽을 부술 기회가 있고 (flag==1), 벽을 만났을 때,
				if (map[nx][ny] && flag) {
					q.push(make_pair(make_pair(nx, ny), 0));
					visited[nx][ny][flag - 1] = visited[x][y][flag] + 1;
				}
                // 이동할 수 있고 방문하지 않았을 때, (일반 이동)
				else if (!map[nx][ny] && !visited[nx][ny][flag]) {
					q.push(make_pair(make_pair(nx, ny), flag));
					visited[nx][ny][flag] = visited[x][y][flag] + 1;
				}
			}
		}
	}
	return -1;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < str.size(); j++) {
			map[i][j] = str[j] - '0';
		}
	}
	cout << bfs() << endl;
}