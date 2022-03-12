#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int dx[8] = { 1, 0, -1, 0, -1, 1, 1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int map[51][51];
bool visited[51][51];

int N, M;
vector<pair<int, int>> v;

int bfs(int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	int cnt = 0;
	q.push({{ x, y }, 0});  
	visited[x][y] = true;
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
				if (map[nx][ny] == 1) {  // 상어를 만나면 return
					return cnt+1;
				}
				else {
					q.push({ { nx, ny }, cnt+1});  // 이동가능하다면 cnt+1로 push
					visited[nx][ny] = true;
				}
			}
		}
	}
	return cnt+1;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 1)
				v.push_back({ i, j });  // 시작 위치 담기
		}
	}
	int result = 0;
	for (int i = 0; i < v.size(); i++) {
		int nx = v[i].first;
		int ny = v[i].second;
		memset(visited, false, sizeof(visited));  // visited 배열 초기화
		result = max(result, bfs(nx, ny));  // max 함수로 최대값 찾기
	}
	cout << result << endl;
}