// dp로 풀어보자

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int house[17][17];
int N;
int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 1, 0 };
queue<pair<pair<int, int>, int>> q;
void check_around(int x, int y, int d) {
	int nx = x + dx[d];
	int ny = y + dy[d];
	int dir = d;
	if (house[nx][ny] == 0 && nx > 0 && nx <= N && ny > 0 && ny <= N) {
		if (dir == 1) {
			if (house[nx - 1][ny] != 0 || house[nx][ny - 1] != 0) {
				return;
			}
		}
		q.push(make_pair(make_pair(nx, ny), dir));
	}
}

void solution(int x, int y) {
	// queue<pair<pair<int, int>, pair<int, int> > > q;
	int count = 0;
	q.push({ { x, y }, 0});
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		int dir = q.front().second;
		q.pop();
		if (x == N && y == N) {
			count++;
		}
		if (dir == 0) {
			for (int j = 0; j < 2; j++) {
				check_around(x, y, j);
			}
		}
		else if (dir == 2) {
			for (int j = 0; j < 3; j++) {
				if (j == 0) continue;
				check_around(x, y, j);
			}
		} else if(dir == 1) {
			for (int j = 0; j < 3; j++) {
				check_around(x, y, j);
			}
		}
	}
	cout << count << endl;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> house[i][j];
		}
	}
	solution(1, 2);
}