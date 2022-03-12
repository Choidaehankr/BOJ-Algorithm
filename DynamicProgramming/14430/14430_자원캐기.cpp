#include <iostream>
#include <algorithm>
#define MAX 301

using namespace std;

int N, M;

int area[MAX][MAX];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> area[i][j];
		}
	}

	// 로봇 WOOK은 오른쪽 (X, Y+1), 아래(X+1, Y) 한 칸 이동 가능
	// 현재 위치 직전 까지의 자원의 최대값을 구해야하므로
	// 탐색 좌표는 (왼쪽 [X][Y-1] / 위 [X-1][Y])

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			area[i][j] += max(area[i - 1][j], area[i][j - 1]);
		}
	}
	cout << area[N][M] << endl;
}