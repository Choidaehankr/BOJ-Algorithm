#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

char arr[101][101];
bool visited[101][101];
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };
int N, non_result = 0, result = 0;

// 적록색약이 아닌 사람
void non_color_weakness(int x, int y) {
	char color = arr[x][y];
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	visited[x][y] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || ny >= N || nx >= N || visited[nx][ny]) continue;
			// 무조건 탐색을 시작한 색상과 인접한 색상이 같아야만 같은 구역으로 인식
			if (arr[nx][ny] == color) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}

// 적록색약인 사람
void color_weakness(int x, int y) {
	char color = arr[x][y];
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	visited[x][y] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || ny >= N || nx >= N || visited[nx][ny]) continue;
			// 탐색을 시작한 색상이 'R' 또는 'G'인 경우, 인접한 색상이 'B'가 아니라면 같은 구역으로 인식
			if (color == 'R' || color == 'G') {  
				if (arr[nx][ny] != 'B') {
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
			}
			else {
				if (color == arr[nx][ny]) {
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str; cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				non_color_weakness(i, j);
				non_result++;
			}
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				color_weakness(i, j);
				result++;
			}
		}
	}
	cout << non_result << ' ' << result << endl;
}