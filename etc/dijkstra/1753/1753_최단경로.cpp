#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e8

using namespace std;

int vertex, edge, k;
vector<pair<int, int>> vec[20001];
int dist[20001];

void dijkstra(int idx) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	dist[idx] = 0;
	pq.push(make_pair(0, idx));
	while (!pq.empty()) {
		int cur = pq.top().second;
		int len = pq.top().first;
		pq.pop();
		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first;  // cur과 연결된 다음 방문할 노드
			int nLen = vec[cur][i].second;  // cur부터 next 까지의 거리
			if (dist[next] > len + nLen) {
				dist[next] = len + nLen;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}


int main() {
	cin >> vertex >> edge >> k;
	for (int i = 0; i < edge; i++) {
		int u, v, w;
		cin >> u >> v >> w;  // u에서 v로 가는 가중치 w인 간선 존재
		vec[u].push_back(make_pair(v, w));
	}
	fill(dist, dist + (vertex + 1), INF);
	dijkstra(k);
	for (int i = 1; i <= vertex; i++) {
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
}