#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 50

int lab[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 0, 0, 1 , -1 };
int dy[4] = { 1, -1, 0, 0 };

int N, M;
int answer = 1e9;

vector<pair<int, int> > virus;

/*
	연구소에 모두 바이러스가 확산되었는지 확인하는 함수
*/
bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (lab[i][j] != 1 && dist[i][j] == -1) {
				return false;
			}
		}
	}
	return true;
}

int solution() {
	queue<pair<int, int> > q;
	int result = 0;
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < virus.size(); i++) {
		q.push(make_pair(virus[i].first, virus[i].second));
		dist[virus[i].first][virus[i].second] = 0;  // 바이러스를 놓을 곳을 0이라 표시
	}
	/*
		bfs 탐색
	*/
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (lab[nx][ny] != 1 && dist[nx][ny] == -1) {
					dist[nx][ny] = dist[x][y] + 1;  // dist 배열에 경과한 시간을 표시
					result = dist[nx][ny];
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return result;
}

/*
	바이러스를 놓을 수 있는 모든 경우 구하기 (dfs)
*/
void selectVirus(int x, int y, int cnt) {
	if (cnt == M) {
		int sum = solution();
		if (check()) {
			answer = min(sum, answer);
		}
		return;
	}
	for (int i = x; i < N; i++) {
		for (int j = y; j < N; j++) {
			if (lab[i][j] != 2 || visited[i][j]) {
				continue;
			}
			visited[i][j] = true;
			virus.push_back(make_pair(i, j));
			selectVirus(i, j, cnt + 1);
			visited[i][j] = false;
			virus.pop_back();
		}
		y = 0;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> lab[i][j];
		}
	}
	selectVirus(0, 0, 0);
	if (answer == 1e9) {
		cout << -1 << endl;
	}
	else {
		cout << answer << endl;
	}
}