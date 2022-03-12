// 4963 섬의 개수
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int r=0, c=0;
int arr[51][51];
int dx[8] = {1, 0, -1, 0, -1, 1, 1, -1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
void init() {
	memset(arr, 0, sizeof(arr));
}

void input(int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	arr[x][y] = 0;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < r && ny < c && arr[nx][ny] == 1) {
				q.push({ nx, ny });
				arr[nx][ny] = 0;
			}
		}
	}
}

int main() {
	while (1) {
		int cnt = 0;  // cnt 초기화
		cin >> c >> r;
		if (r == 0 && c == 0)  // 입력이 모두 0일경우 종료
			break;
		init();  // 배열 초기화
		input(r, c);  // 배열 입력 받기
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] == 1) {  // 섬이라면 bfs 탐색
					bfs(i, j);
					cnt++;  // bfs 탐색을 마칠때마다 섬의 개수 1증가
				}
			}
		}
		cout << cnt << endl;
	}
}