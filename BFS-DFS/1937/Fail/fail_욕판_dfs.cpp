#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n;
int forest[500][500];
bool visited[500][500];
int result = 0;
void solution(int x, int y, int num, int cnt) {
	if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y]) {
		return;
	}
	if (forest[x][y] < num) return;
	visited[x][y] = true;
	solution(x + 1, y, forest[x][y], cnt + 1);
	solution(x, y + 1, forest[x][y], cnt + 1);
	solution(x - 1, y, forest[x][y], cnt + 1);
	solution(x, y - 1, forest[x][y], cnt + 1);
	result = max(result, cnt);
}

int main() {
	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> forest[i][j];
		}
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			memset(visited, false, sizeof(visited));
			solution(i, j, forest[i][j], 1);
		}
	}
	cout << result << endl;
}