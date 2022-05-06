#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100001
#define INF 1e8
using namespace std;

int N, M, from, goal;
int dist[MAX];
vector<pair<int, int> > v[MAX];

void solution(int idx) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	dist[idx] = 0;
	pq.push(make_pair(0, idx));
	while (!pq.empty()) {
		int cur = pq.top().second;
		if (cur == goal) return;
		int cost = pq.top().first;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nCost = v[cur][i].second;
			if (dist[next] > cost + nCost) {
				dist[next] = cost + nCost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}
int main() {
	cin >> N >> M;
	fill(dist, dist + N + 1, INF);
	for (int i = 0; i < M; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		v[start].push_back(make_pair(end, cost));
	}
	cin >> from >> goal;
	solution(from);
	cout << dist[goal] << endl;
}