#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<int, int> > v[10002];
bool visited[10002];
int n, sum = 0, dest = 0;

void dfs(int idx, int weight) {
	if (visited[idx]) return;  // 방문 노드 확인
	visited[idx] = true;
	if (sum < weight) {  // 현재 노드까지의 거리가 가장 멀다면 최대 거리 갱신
		sum = weight;
		dest = idx;
	}
	for (int i = 0; i < v[idx].size(); i++) {  // 연결되어있는 노드들 탐색
		dfs(v[idx][i].first, weight + v[idx][i].second);
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n-1; i++) {
		int start, end, val;
		cin >> start >> end >> val;
		v[start].push_back(make_pair(end, val));
		v[end].push_back(make_pair(start, val));
		if (end == n) break;
	}
	// 루트 노드에서 가장 멀리 떨어진 정점은 원의 지름에 해당하는 부분 (dest)
	dfs(1, 0);
	sum = 0;
	memset(visited, false, sizeof(visited));
	// dest에서 가장 먼 노드 탐색.
	dfs(dest, 0);
	cout << sum << endl;
}