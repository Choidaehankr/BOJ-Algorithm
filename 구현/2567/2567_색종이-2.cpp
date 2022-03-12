#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int paper[101][101];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 현재 위치가 1이고 4방향 탐색을 했을 때 0이 있을 경우 '둘레'

void checking(int x, int y) {
	for (int i = x; i < x + 10; i++) {
		for (int j = y; j < y + 10; j++) {
			paper[i][j] = 1;  // 색종이가 있는 부분을 1로 채우기
		}
	}
}

int counting_round(int x, int y) {
	bool flag = false;
	int ans = 0;
	// 4방향 탐색을 했을 때 0의 개수 만큼 ans를 증가. ans = 둘레
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 101 && ny >= 0 && ny < 101) {
			if (paper[nx][ny] == 0) {
				flag = true;
				ans++;
			}
		}
	}

	if (flag) {
		return ans;
	}
	else 
		return 0;
}

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int r, c;
		cin >> r >> c;
		checking(r, c);
	}
	int cnt = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (paper[i][j] == 1) {
				cnt += counting_round(i, j);  // 확인한 둘레의 길이를 누적시킴
			}
		}
	}
	cout << cnt << endl;
}