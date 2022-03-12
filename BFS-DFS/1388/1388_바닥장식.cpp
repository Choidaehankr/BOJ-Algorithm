#include <iostream>
#include <queue>
#define MAX 50
using namespace std;

int N, M;
char room[MAX][MAX];
queue<pair<int, int>> q;
int cnt = 0;
// '-'는 오른쪽으로만 이동 / '|'는 아래로만 이동. 이동했다면 'x'로 체크해줘서 방문 표시
void solution(int x, int y, char c) {
	q.push({ x, y });
	room[x][y] = 'x';
	int dx, dy;
	if (c == '-') {  // 오른쪽 이동
		dx = 0, dy = 1;
	}
	else if (c == '|') {  // 아래로 이동
		dx = 1, dy = 0;
	}
	while (!q.empty()) {
		int nx = q.front().first + dx;
		int ny = q.front().second + dy;
		q.pop();
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && room[nx][ny] != 'x') {
			if (room[nx][ny] == c) {
				q.push({ nx, ny });
				room[nx][ny] = 'x';
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (room[i][j] != 'x') {
				solution(i, j, room[i][j]);
				cnt += 1;  // 필요한 장식의 개수 증가
			}
		}
	}
	cout << cnt << endl;
}