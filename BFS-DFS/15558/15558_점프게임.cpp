#include <iostream>
#include <string>
#include <queue>
#define MAX 100001
using namespace std;

int arr[2][MAX];
bool visited[2][MAX];
int N, K;

int dx[4] = {0, 0, 1, -1};  // (인덱스) 0-1: 앞, 뒤 / 2-3: 옆칸이동
int dy[4] = {1, -1, 0, 0};

queue<pair<pair<int, int>, int>> q;


void bfs() {
	q.push({{ 0, 0 }, 0});
	visited[0][0] = true;
	bool flag = false;
	while (!q.empty() && !flag) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;  // 초가 지날때마다 사라지는 칸
		q.pop();

		if (cnt >= N) {  // 종료 조건
			break;
		}

		for (int i = 0; i < 2; i++) {  // 앞 뒤로 움직임
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (ny >= N) {  // 마지막 칸 도달
				flag = true;
			}
			if (nx >= 0 && nx < 2 && ny > cnt && ny < N && !visited[nx][ny]) {
				if (arr[nx][ny] == 1) {
					visited[nx][ny] = true;
					q.push({ {nx, ny}, cnt + 1 });  // 사라지는 칸을 증가
				}
			}
		}
		for (int i = 2; i < 4; i++) {  // 옆 칸으로 움직임 (줄 전환 + K칸 이동)
			int nx = x + dx[i];
			int ny = y + dy[i] + K;
			if (ny >= N) {  // 마지막 칸 도달
				flag = true;
			}
			if (nx >= 0 && nx < 2 && ny > cnt && ny < N && !visited[nx][ny]) {
				if (arr[nx][ny] == 1) {
					visited[nx][ny] = true;
					q.push({ {nx, ny}, cnt + 1 });
				}
			}
		}
	}
	if (flag)
		cout << 1 << endl;
	else
		cout << 0 << endl;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < 2; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			arr[i][j] = str[j]-48;
		}
	}
	bfs();
}