#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[103][103];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			// 현재 블록에서 4방향 탐색을 진행
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				int sub = arr[i][j] - arr[nx][ny];  // 현재 블록에서 높이 차를 구함
				if (sub > 0) {  // 현재 블록의 높이가 더 높을 경우 sub에 누적
					sum += sub;
				}
			}
		}
	}
	sum += 2 * N * M;  // 마지막으로 윗면과 밑면의 넓이를 더해줌

	cout << sum;
}