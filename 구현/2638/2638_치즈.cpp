#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int board[100][100];
bool air[100][100];
int n, m, result = 0;

vector<pair<int, int> > cheese;
vector<pair<int, int> > v;


void init() {
	v.clear();
	cheese.clear();
	memset(air, false, sizeof(air));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1)
				cheese.push_back(make_pair(i, j));
		}
	}
}

bool check_no_cheese() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1)
				return false;
		}
	}
	return true;
}

void check_air() {
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	air[0][0] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || air[nx][ny] || board[nx][ny] == 1) continue;
			if (board[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				air[nx][ny] = true;
			}
		}
	}
}

void melt(vector<pair<int, int> > v) {  // 치즈를 녹았다고 표시해준다. (board[x][yy] = 0)
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		board[x][y] = 0;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	while (!check_no_cheese()) {  // board에 1이 없을 때 까지 진행
		init();
		check_air();
		for (int i = 0; i < cheese.size(); i++) {
			int cnt = 0;
			int x = cheese[i].first;
			int y = cheese[i].second;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (air[nx][ny] == 1) cnt++;
			}
			if (cnt >= 2) {  // 2면 이상이 공기와 닿아 녹을 치즈를 v에 push_back
				v.push_back(make_pair(x, y));
			}
		}
		melt(v);  // 치즈를 녹인다.
		result += 1;
	}
	cout << result << endl;
}