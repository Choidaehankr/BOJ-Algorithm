#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int forest[501][501];
int dp[501][501];
int mv[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
int n, answer = 0;


int solution(int x, int y) {
	int cur = forest[x][y];  // 현재 위치의 대나무 개수

	// 이전에 방문한적이 없다면
	if (!dp[x][y]) {
		dp[x][y] = 1;  // 방문 체크, 최소 1번 이동한 것이므로 현재 위치를 1로 지정
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			// 상하좌우 이동
			int nx = x + mv[i][0];
			int ny = y + mv[i][1];
			// 다음 이동할 곳이 현재 위치보다 대나무가 더 적다면 이동하지 않음
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || forest[nx][ny] <= cur)  
				continue;
			cnt = max(cnt, solution(nx, ny));  // 현재 위치에서 재귀 탐색으로 가장 멀리 이동할 수 있는 값
		}
		dp[x][y] += cnt;  // 해당 값을 현재 위치에 저장 (현재 위치에서 cnt 만큼 더 이동할 수 있다.)
	}
	return dp[x][y];
}

int main() {
	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> forest[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer = max(answer, solution(i, j));  // 모든 위치를 시작점으로 두고 탐색해서 최대값을 찾는다.
		}
	}
	cout << answer << endl;
}