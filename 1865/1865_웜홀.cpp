#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 1e9
using namespace std;

int dist[501];
int N, M, W;
vector<pair<pair<int, int>, int>> v;

// 최단 거리는 관심 없고, 음의 사이클의 존재 유무만 파악하면 된다.

// dist에 INF값을 설정하는 이유는 단절이 되었다를 표시하고, 어떤 지점으로 부터의 거리를 구하려고 할 때 쓰인다.
// 따라서 단순 그래프에서 사이클 유무만 파악할 때는 dist 초기화를 어떤 값으로 하든 상관없다.
string bellmanFord() {
	dist[1] = 0;
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 0; j < v.size(); j++) {
			int start = v[j].first.first;
			int end = v[j].first.second;
			int weight = v[j].second;

			if (dist[start] == INF) continue;
			if (dist[end] > dist[start] + weight)
				dist[end] = dist[start] + weight;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int start = v[i].first.first;
		int end = v[i].first.second;
		int weight = v[i].second;
		if (dist[start] == INF) continue;
		if (dist[end] > dist[start] + weight) {  // 음의 사이클이 존재
			return "YES";
		}
	}
	return "NO";
}


int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		cin >> N >> M >> W;
		v.clear();
		// fill(dist, dist + 501, INF);
		//memset(dist, -1, sizeof(dist)); 초기화를 아예 안해줘도 통과
		for (int i = 0; i < M; i++) {
			int start, end, weight;
			cin >> start >> end >> weight;
			v.push_back(make_pair(make_pair(start, end), weight));
			v.push_back(make_pair(make_pair(end, start), weight));
		}
		for (int i = 0; i < W; i++) {
			int start, end, weight;
			cin >> start >> end >> weight;
			v.push_back(make_pair(make_pair(start, end), -weight));
		}
		cout << bellmanFord() << endl;
	}
}