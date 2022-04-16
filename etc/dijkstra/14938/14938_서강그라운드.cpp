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
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
}

int dijkstra(int idx) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	dist[idx] = 0;
	q.push({ idx, 0 });
	int sum = 0;
	while (!q.empty()) {
		int cur = q.top().first;
		int d = q.top().second;
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int n_dist = v[cur][i].second;
			if (dist[next] > d + n_dist) {
				dist[next] = d + n_dist;
				q.push({ next, dist[next] });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] <= m) {
			sum += val[i];
		}
	}
	return sum;
}

int main() {
	cin >> n >> m >> r;  // 지역, 범위, 길 개수
	for (int i = 1; i <= n; i++)
		cin >> val[i];
	for (int i = 0; i < r; i++) {
		int from, to, d;
		cin >> from >> to >> d;
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