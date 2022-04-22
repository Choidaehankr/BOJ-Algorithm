#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n, m, result = 0;
int copyArr[8][8], arr[8][8];
int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { 1, 0, 0, -1 };

void copy(int src[8][8], int dest[8][8]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			src[i][j] = dest[i][j];
		}
	}
}
void bfs() {
	int tmp[8][8];
	copy(tmp, copyArr);
	// 1040ms
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 2) {
				queue<pair<int, int> > q;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (tmp[nx][ny] == 0) {
							q.push(make_pair(nx, ny));
							tmp[nx][ny] = 2;
						}
					}
				}
			}
		}
	}
	// 232 ms
	//queue<pair<int, int>> q;
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		if (tmp[i][j] == 2) {
	//			q.push(make_pair(i, j));
	//		}
	//	}
	//}
	//while (!q.empty()) {
	//	int x = q.front().first;
	//	int y = q.front().second;
	//	q.pop();
	//	for (int k = 0; k < 4; k++) {
	//		int nx = x + dx[k];
	//		int ny = y + dy[k];
	//		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
	//		if (tmp[nx][ny] == 0) {
	//			q.push(make_pair(nx, ny));
	//			tmp[nx][ny] = 2;
	//			// visited[nx][ny] = true;
	//		}
	//	}
	//}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) 
				cnt++;
		}
	}
	result = max(result, cnt);
}


void setWall(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copyArr[i][j] == 0) {
				copyArr[i][j] = 1;
				setWall(cnt + 1);
				copyArr[i][j] = 0;  // 벽을 다시 0으로 초기화
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				copy(copyArr, arr);  // copyArr에 Arr를 복사
				copyArr[i][j] = 1;  // 벽 1개 세우기.
				setWall(1);
				copyArr[i][j] = 0;
			}
		}
	}
	cout << result << endl;
}