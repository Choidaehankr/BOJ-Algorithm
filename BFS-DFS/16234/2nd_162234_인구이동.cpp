#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int land[51][51];
bool visited[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, L, R;
bool flag = false;

// bool checkMovePossible(int x, int y) {
void checkMovePossible(int x, int y) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	q.push({ x, y });
	visited[x][y] = true;
	v.push_back({ x, y });
	// bool flag = false;
    int popCnt = land[x][y];  // change
	int cnt = 1;
	/*cout << "*********visited Checking********" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << ' ';
		}
		cout << endl;
	}*/
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny]) {
				if (abs(land[x][y] - land[nx][ny]) >= L && abs(land[x][y] - land[nx][ny]) <= R) {
					//cout << "im visiting now " << nx << " " << ny << endl;
					cnt += land[nx][ny];
					v.push_back({ nx, ny });
					q.push({ nx, ny });
					visited[nx][ny] = true;
					flag = true;
				}
			}
		}
	}
	int len = v.size();
	for (int i = 0; i < len; i++) {
		int nx = v[i].first;
		int ny = v[i].second;
		//cout << " cnt / v.size() is " << cnt / v.size() << endl;
		land[nx][ny] = (cnt / len);
	}
	
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> land[i][j];
		}
	}
	int result = 0;
	while (1) {
		flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				checkMovePossible(i, j);
			}
		}
		if (!flag) {
			cout << result << endl;
			return 0;
		}
		else {
			result++;
		}
		memset(visited, false, sizeof(visited));
	}
}
