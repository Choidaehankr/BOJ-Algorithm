#include <iostream>
using namespace std;
int N, M;
int arr[50][50];
int r, c, d;
bool check[50][50];
int dx[4] = { -1, 0, 1, 0 };  // 북, 동, 남, 서
int dy[4] = { 0, 1, 0, -1 };

int turn_left(int dir) {  // 왼쪽으로 방향 전환. ex) 0(북)-> 3(서)으로 전환
	switch (dir) {
		case 0:
			return 3;
		case 1:
			return 0;
		case 2:
			return 1;
		case 3:
			return 2;
	}
}

void solution(int r, int c, int d) {
	int cnt = 0;
	check[r][c] = true;  // 청소 여부를 체크
	cnt++;  // 청소한 칸 수 증가
	int nx, ny, nd;
	while (1) {
		int prev_d = d;  // 후진하기 위한 회전하기 이전의 방향 저장
		bool can_clean = false;  // 왼쪽 방을 청소할 수 있는지 여부
		int can_not_clean = 0;  // 4방향 모두 청소할 수 없는지 여부를 판단
		for (int i = 0; i < 4; i++) {
			nd = turn_left(d);  // 왼쪽으로 방향 전환
			nx = r + dx[nd];  // 회전한 방향으로 전진
			ny = c + dy[nd];

			if (arr[nx][ny] == 0 && !check[nx][ny]) {  // 벽이 아니고 청소를 아직 안했다면,
				can_clean = true;
				break;
			}
			else if (arr[nx][ny] == 1 || check[nx][ny] || nx < 0 || nx >= N || ny < 0 || ny >= M) {  // 범위 밖이거나 벽이거나 이미 청소를 했다면
				d = nd;  // 4방향 탐색을 위한 회전
				can_not_clean++;  // 4가 될경우 조건 2-c.에 따라 바라보는 방향을 유지하고 한칸 후진
			}
		}
		if (can_clean) {  // 왼쪽 칸을 청소할 수 있을 경우
			check[nx][ny] = true;
			cnt++;
			d = nd;  // 방향 유지
		}
		if (can_not_clean >= 4) {  // 후진
			nx = r - dx[prev_d];  // 직전에 바라보던 방향을 유지 [prev_d]
			ny = c - dy[prev_d];
			d = prev_d;
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] == 1) {  // 모두 청소를 했고, 벽일 경우 종료
				break;
			}
		}
		r = nx;  // 현재 위치 갱신
		c = ny;
	}
	cout << cnt << endl;
}
int main() {
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	solution(r, c, d);
}