//#include <iostream>
//#include <queue>
//#include <algorithm>
//#include <vector>
//#include <cstring>
//using namespace std;
//int land[51][51];
//int tmpLand[51][51];
//bool visited[51][51];
//int dx[4] = { -1, 0, 1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//int N, L, R;
//bool flag = true;
//void checkMovePossible(int x, int y) {
//	if (visited[x][y]) return;
//	else visited[x][y] = true;
//
//	queue<pair<int, int>> q;
//	vector<pair<int, int>> v;
//
//	q.push({ x, y });
//	v.push_back({ x, y });
//	int population = land[x][y]; 
//	int cnt = 1;
//
//	while (!q.empty()) {
//		x = q.front().first;
//		y = q.front().second;
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			int sub = abs(land[x][y] - land[nx][ny]);
//			if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny]) {
//				if (sub >= L && sub <= R) {
//					visited[nx][ny] = true;
//					flag = true;
//					cnt++;
//					population += land[nx][ny];
//					q.push({ nx, ny });
//					v.push_back({ nx, ny });
//				}
//			}
//		}
//	}
//	for (int i = 0; i < v.size(); i++) {
//		int nx = v[i].first;
//		int ny = v[i].second;
//		land[nx][ny] = population / cnt;
//	}
//}
//int main() {
//	cin >> N >> L >> R;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> land[i][j];
//		}
//	}
//	int result = 0;
//	while (true) {
//		flag = false;
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				checkMovePossible(i, j);
//			}
//		}
//		if (!flag)
//			break;
//		result++;
//		memset(visited, false, sizeof(visited));
//	}
//	cout << result << endl;
//}


#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int land[51][51];
bool visited[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, L, R;
bool flag = false;

void checkMovePossible(int x, int y) {
	if (visited[x][y]) return;  // 이거 한줄 때문에 계속 틀린거였다...
	visited[x][y] = true;
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	q.push({ x, y });
	v.push_back({ x, y });
	int popCnt = land[x][y];
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny]) {
				if (abs(land[x][y] - land[nx][ny]) >= L && abs(land[x][y] - land[nx][ny]) <= R) {
					popCnt += land[nx][ny];
					v.push_back({ nx, ny });
					q.push({ nx, ny });
					visited[nx][ny] = true;
					flag = true;
				}
			}
		}
	}
	int len = v.size();
	for (int i = 0; i < v.size(); i++) {
		int nx = v[i].first;
		int ny = v[i].second;
		land[nx][ny] = popCnt / v.size();
	}

}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> land[i][j];
		}
	}
	int result = 0;
	while (1) {
		flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				checkMovePossible(i, j);
			}
		}
		if (!flag) {
			break;
		}
		else {
			result++;
		}
		memset(visited, false, sizeof(visited));
	}
	cout << result << endl;
}
