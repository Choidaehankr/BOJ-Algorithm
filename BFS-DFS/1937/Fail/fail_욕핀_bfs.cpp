/**
 * BFS 시간초과
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n;
int forest[500][500];
bool visited[500][500];
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int solution(vector<vector<int>> copyVec, int x, int y, int num) {
	memset(visited, false, sizeof(visited));
	queue<pair<pair<int, int>, int> > q;

	int tmp = num;
	int cnt = 1;

	q.push(make_pair(make_pair(x, y), cnt));
	visited[x][y] = true;

	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		cnt = q.front().second;
		tmp = copyVec[x][y];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = x + mv[i][0];
			int dy = y + mv[i][1];
			if (dx >= 0 && dx < n && dy >= 0 && dy < n && !visited[dx][dy]) {
				if (copyVec[dx][dy] > tmp) {
					q.push(make_pair(make_pair(dx, dy), cnt + 1));
					visited[dx][dy] = true;
				}
			}
		}
	}
	return cnt;
}

int main() {
	cin >> n;
	int num;
	vector<vector<int> > v;
	for (int i = 0; i < n; i++) {
		vector<int> tmpVec;
		for (int j = 0; j < n; j++) {
			cin >> num;
			tmpVec.push_back(num);
		}
		v.push_back(tmpVec);
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer = max(answer, solution(v, i, j, v[i][j]));
		}
	}
	cout << answer << endl;
}