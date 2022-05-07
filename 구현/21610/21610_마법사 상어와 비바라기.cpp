#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int arr[51][51];
bool visited[51][51];
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1 };  // 8방향 이동
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1 };
int N, M;

vector<pair<int, int> > v;

void move_cloud(int dir, int num) {  // 참고..
	for (int i = 0; i < v.size(); i++) {
		int nx = v[i].first + dx[dir-1] * num;
		int ny = v[i].second + dy[dir-1] * num;
		while (nx < 0) {
			nx += N;
		}
		while (nx >= N) {
			nx -= N;
		}
		while (ny < 0) {
			ny += N;
		}
		while (ny >= N) {
			ny -= N;
		}
		v[i].first = nx;
		v[i].second = ny;
	}
}

void rain() {
	for (int i = 0; i < v.size(); i++) {
		int nx = v[i].first;
		int ny = v[i].second;
		arr[nx][ny] += 1;
		visited[nx][ny] = true;  // 물의양을 1씩 증가시키면서, 구름이 있던 위치를 표시
	}
}

void copy_rain() {
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		int cnt = 0;
		for (int j = 1; j <= 8; j += 2) {  // 대각선이므로 2씩 증가
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && arr[nx][ny] != 0) { // > 0
				cnt += 1;
			}
		}
		arr[x][y] += cnt;
	}
}

void make_cloud() {
	v.clear();
	// 물의 양이 2보다 크고, 직전에 구름이 생성된 곳이 아니라면 구름 생성
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] >= 2 && !visited[i][j]) {
				v.push_back({ i, j });
				arr[i][j] -= 2;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	v.push_back({ N - 1, 0 });
	v.push_back({ N - 1, 1 });
	v.push_back({ N - 2, 0 });
	v.push_back({ N - 2, 1 });

	for (int i = 0; i < M; i++) {
		int dir, num;
		cin >> dir >> num;
		memset(visited, false, sizeof(visited));
		move_cloud(dir, num);
		rain();
		copy_rain();
		make_cloud();
	}

	int result = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			result += arr[i][j];
		}
	}
	cout << result;
}