#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 51
using namespace std;

int city[MAX][MAX];
int N, M;

vector<pair<int, int>> house;  // 치킨집과의 최단 거리를 찾기위해 집의 위치들을 vector에 넣음.
vector<pair<int, int>> chick;
vector<pair<int, int>> temp;

// 벡터 v에서 M개 고른 조합을 모두 temp 벡터에 push.
// v의 원소가 1, 2, 3, 4, 5이고, M이 2일 경우)
// temp = (1, 2) (1, 3) (1, 4) (1, 5) (2, 3) (2, 4) ... (4, 5)가 존재
void combination(vector<pair<int, int>> v, vector<pair<int, int>> comb, int r, int idx, int depth) {
	if (r == 0) {
		for (int i = 0; i < comb.size(); i++) {
			temp.push_back({ comb[i].first, comb[i].second });
		}
	}
	else if (depth == v.size()) {
		return;
	}
	else {
		comb[idx] = v[depth];
		combination(v, comb, r - 1, idx + 1, depth + 1);
		combination(v, comb, r, idx, depth + 1);
	}
}

// 집(city[x][y]==1)에서 시작해서 치킨집(city[i][j]==2)를 만날 경우 |x-i| + |y-j|의 최소값을 구함.
int find_distance(int x, int y) {
	int dist = MAX*MAX;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (city[i][j] == 2) {
				dist = min(dist, abs(x - i) + abs(y - j));
			}
		}
	}
	return dist;
}


int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num; cin >> num;
			if (num == 1) {  // 집일 경우 house 벡터에 push
				house.push_back({ i, j });
			}
			else if (num == 2) {  // 치킨집일 경우, city 배열은 0으로 두고, chick 벡터에 push
				chick.push_back({ i, j });
				continue;
			}
			city[i][j] = num;
		}
	}
	vector<pair<int, int>> comb(M);
	combination(chick, comb, M, 0, 0);  // chick 벡터에서 M개 고르는 조합

	int res = MAX*MAX;

	for (int i = 0; i < temp.size(); i+=M) {  
		int ans = 0;
		for (int j = i; j < i+M; j++) {
			city[temp[j].first][temp[j].second] = 2; // temp에서 M개 만큼 돌며 치킨집의 위치를 갱신시킴
		}
		for (int i = 0; i < house.size(); i++) {
			int x = house[i].first;
			int y = house[i].second;
			ans += find_distance(x, y);  // 각 집에서 부터 치킨집까지 최단거리 찾기
		}
		res = min(res, ans); // 치킨집이 M개 존재할 때 최단거리 찾기
		for (int j = i; j < i + M; j++) {
			city[temp[j].first][temp[j].second] = 0;  // 다시 0으로 초기화
		}
	}
	cout << res << endl;
}