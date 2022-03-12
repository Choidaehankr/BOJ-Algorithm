#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#define MAX 1001
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };
using namespace std;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int M, N;

vector<pair<int, int>> v;
queue<pair<int, int>> q;

bool solution(int x, int y) {
	visited[x][y] = true;  // 시작 좌표 방문 표시 후 queue에 push
	q.push({ x, y });
	while (!q.empty()) {
		int cur_x = q.front().first;  // 현재 좌표
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {  // 4방향 탐색
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N && !visited[nx][ny]) {  // 배열 범위 내에 있고, 방문하지 않았을 경우
				if (arr[nx][ny] == 0) {  // 전류가 통하는 경우에만 추가 탐색을 위해 queue에 push후 방문 표시
					q.push({ nx, ny });
					visited[nx][ny] = true;
				}
				if (nx == M - 1)  // 안쪽까지 잘 전달될 경우 true를 return
					return true;
			}
		}
	}
	return false;  // 안쪽까지 전달되지 않았을 경우 false를 return
}
int main() {
	cin >> M >> N;
	string str;
	for (int i = 0; i < M; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j] - '0';
			if (i == 0 && arr[i][j] == 0) {  // '바깥쪽'의 좌표를 저장
				v.push_back({ i, j });
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int cur_x = v[i].first;
		int cur_y = v[i].second;
		//memset(visited, false, sizeof(visited));
		if (solution(cur_x, cur_y)) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}