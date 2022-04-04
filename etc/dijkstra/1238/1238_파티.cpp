#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 1e8
using namespace std;

vector<pair<int, int> > graph[10001];
int dist[10001];
int sumDist[10001];
int n, m, x;

priority_queue<int> ans;
void dijkstra(int start) {
	fill(dist, dist + 10001, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		int d = pq.top().first;  // 현재 노드까지 비용
		int cur = pq.top().second;  // 현재 노드
		pq.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int val = graph[cur][i].second;
			if (dist[next] > val + d) {
				dist[next] = val + d;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}

int main() {
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int start, end, val;
		cin >> start >> end >> val;
		graph[start].push_back(make_pair(end, val));  // start에서 end로 가는 가중치가 val이다.
	}

	for (int i = 1; i <= n; i++) {
		dijkstra(i);  // i번째 노드부터 방문할 수 있는 노드까지의 dijkstra 탐색
		sumDist[i] = dist[x];  // dijkstra 탐색을 마친 후 i번 노드부터 x번 노드까지 가는 최단 거리를 갱신한다.
	}
	dijkstra(x);  // x번 노드부터 각 노드로 가는 최단 거리를 탐색
	int result = 0;
	for (int i = 1; i <= n; i++) {
		sumDist[i] += dist[i];  // 현재 dist배열엔 x번 노드부터 각 노드까지의 최단 거리가 담김. 왕복 거리를 구해야 하므로 sumDist에 dist를 더해줌
		result = max(sumDist[i], result);
	}
	cout << result << endl;
}