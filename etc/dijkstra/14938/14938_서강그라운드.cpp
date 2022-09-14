#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e8
using namespace std;

int n, m, r;
int dist[101], val[101];
vector<pair<int, int> > v[101];

void init() {
	// 모든 노드간의 거리를 무한대로 초기화
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
}

int dijkstra(int idx) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	dist[idx] = 0;  // 현재 떨어진 지역(idx)과의 거리는 0
	q.push({ idx, 0 });
	int sum = 0;
	while (!q.empty()) {
		int cur = q.top().first;
		int d = q.top().second;
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int n_dist = v[cur][i].second;
			// 다음 노드 까지의 거리가 = dist[next] 최솟값이 아니라면 갱신
			if (dist[next] > d + n_dist) {
				dist[next] = d + n_dist;
				q.push({ next, dist[next] });
			}
		}
	}
	// 떨어진 지역 (idx)로 부터 수색범위 (m)에 있는 지역의 아이템 수의 합을 구해서 반환
	for (int i = 1; i <= n; i++) {
		if (dist[i] <= m) {
			sum += val[i];
		}
	}
	return sum;
}

int main() {
	cin >> n >> m >> r;  // 지역, 수색 범위, 길 개수
	for (int i = 1; i <= n; i++)
		// 해당 지역의 아이템 수
		cin >> val[i];  
	for (int i = 0; i < r; i++) {
		// from에서 to까지 거리: d
		int from, to, d;  
		cin >> from >> to >> d;
		// 양방향 통행이 가능함
		v[from].push_back(make_pair(to, d));
		v[to].push_back(make_pair(from, d));
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		init();
		result = max(dijkstra(i), result);
	}
	cout << result << endl;
} 