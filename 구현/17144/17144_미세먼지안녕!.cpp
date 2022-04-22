#include <iostream>
using namespace std;

int arr[50][50];
int tmp[50][50];
int ans[50][50];
int r, c, t;
int tx, bx;
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

void copy_arr() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			arr[i][j] = tmp[i][j];
			ans[i][j] = 0;
			tmp[i][j] = 0;
		}
	}
}

void active_cleaner() {
	// top
	for (int i = tx - 1; i > 0; i--) {
		tmp[i][0] = tmp[i - 1][0];
	}
	for (int i = 0; i < c - 1; i++) {
		tmp[0][i] = tmp[0][i + 1];
	}
	for (int i = 1; i <= tx; i++) {
		tmp[i - 1][c - 1] = tmp[i][c - 1];
	}
	for (int i = c - 1; i > 1; i--) {
		tmp[tx][i] = tmp[tx][i-1];
	}
	tmp[tx][1] = 0;
	// bottom
	for (int i = bx + 1; i < r-1; i++) {
		tmp[i][0] = tmp[i + 1][0];
	}
	for (int i = 0; i < c - 1; i++) {
		tmp[r - 1][i] = tmp[r - 1][i + 1];
	}
	for (int i = r - 1; i >= bx; i--) {
		tmp[i][c - 1] = tmp[i - 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) {
		//ans[bx][i] = tmp[bx][i - 1];
		tmp[bx][i] = tmp[bx][i - 1];
	}
	tmp[bx][1] = 0;
	tmp[tx][0] = tmp[bx][0] = -1;

}

void spread_dust(int x, int y, int num, int cnt) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < r && ny >= 0 && ny < c && arr[nx][ny] != -1) {
			tmp[nx][ny] += num / 5;
		}
	}
	tmp[x][y] += num - ((num / 5)*cnt);
}

void check_around() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] != 0 && arr[i][j] != -1) {
					int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] == -1) continue;
					cnt++;
				}
				spread_dust(i, j, arr[i][j], cnt);
			}
		}
	}
}

int main() {
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				bx = i;  // 공기청정기 밑부분
			}
		}
	}
	tx = bx - 1;
	while (t--) {
		check_around();
		active_cleaner();
		copy_arr();
	}
	int result = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			result += arr[i][j];
		}
	}
	cout << result + 2;
} 