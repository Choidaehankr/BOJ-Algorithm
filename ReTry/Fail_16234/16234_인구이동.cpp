#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int N, L, R;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int land[51][51];
bool visit[51][51];
bool openBoarderLine[51][51];


void bfs(int x, int y) {
	memset(visit, false, sizeof(visit));
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	q.push({ x, y });
	v.push_back({ x, y });
	visit[x][y] = true;
	int cnt = land[x][y];
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visit[nx][ny]) {
				if (openBoarderLine[nx][ny] == true) {
					visit[nx][ny] = true;
					cnt += land[nx][ny];
					//cout << "nx " << nx << " ny " << ny << " ----cnt is " << cnt << "------" << endl;
					v.push_back({ nx, ny });
					q.push({ nx, ny });
				}
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int nx = v[i].first;
		int ny = v[i].second;
		openBoarderLine[nx][ny] = false;
		land[nx][ny] = (cnt / v.size());
		// cout << "[nx][ny] is " << nx << ' ' << ny << " average is " << cnt / v.size() << endl;
	}
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << land[i][j] << " ";
		}
		cout << endl;
	}*/
}

bool checkMovePosibillity() {
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int curPopulation = land[i][j];
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visit[nx][ny]) {
					if (abs(land[nx][ny] - curPopulation) >= L && abs(land[nx][ny] - curPopulation) <= R) {
						openBoarderLine[nx][ny] = true;
						visit[nx][ny] = true;
					}
				}
			}
		}
	}
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (openBoarderLine[i][j]) {
				// cout << "===========true!!!=======" << endl;
				return true;
			}
		}
	}
	// cout << "=======false!!=======" << endl;
	return false;
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> land[i][j];
		}
	}
	int answer = 0;
	while (checkMovePosibillity()) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (openBoarderLine[i][j] && !visit[i][j]) {
					// cout << "openBoard[i][j] is " << i << " " << j << endl;
					bfs(i, j);
				}
			}
		}
		memset(openBoarderLine, false, sizeof(openBoarderLine));
		memset(visit, false, sizeof(visit));
		answer++;
	}
	cout << answer << endl;
}