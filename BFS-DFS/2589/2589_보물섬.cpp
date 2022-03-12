#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define MAX 51
using namespace std;
char land[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];
int r, c;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int result = 0;

vector<pair<int, int>> v;

int solution(int x, int y) {  // �ִܰŸ� Ž���� ���� BFSŽ��
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;
	int cnt = 0;
	dist[x][y] = 0;

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		int d = dist[curX][curY];  // ���� �湮�� ��ġ������ �ҿ�� �ð�
		q.pop();
		cnt = max(cnt, d);  // x, y ��ǥ���� �ð��� ���� ���� �ɸ��� ������ ã��
		cout << "curX is " << curX << " curY is " << curY << "cnt is " << cnt << endl;
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny]) {
				if (land[nx][ny] == 'L') {
					q.push({ nx, ny });
					dist[nx][ny] = dist[curX][curY] + 1;  
					// �湮�� �����ϴٸ� ���������� �ҿ� �ð��� 1�� ������
					visited[nx][ny] = true;
				}
			}
		}
	}
	cout << "cnt is " << cnt << endl;
	return cnt;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> land[i][j];
			if (land[i][j] == 'L') {  // ������ �κи� ���Ϳ� push
				v.push_back({ i, j });
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {  // ��� 'L'�� ���������� bfs Ž��
		int nowR = v[i].first;
		int nowC = v[i].second;
		memset(visited, false, sizeof(visited));  // Ž������ visited�� dist�迭�� �ʱ�ȭ
		memset(dist, 0, sizeof(dist));
		result = max(result, solution(nowR, nowC));  
		// ���� ���� �ִܰŸ��� �湮���� ��, ���� ���� �ɸ� �ð� ã��
	}
	cout << result;
}