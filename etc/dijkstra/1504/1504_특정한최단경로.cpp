#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 1e8
using namespace std;

int n, e, v1, v2;
int dist[801];
vector<pair<int, int> > v[801];
int start1, start2, v1_v2, v1_n, v2_n;

void dijkstra(int idx) {
    fill(dist, dist+n+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, idx));
    dist[idx] = 0;

    while(!pq.empty()) {
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int val = v[cur][i].second;
            if(dist[next] > d + val) {
                dist[next] = d + val;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
}

int main() {
    cin >> n >> e;
    for(int i = 0; i < e; i++) {
        int st, end, val;
        cin >> st >> end >> val;
        v[st].push_back(make_pair(end, val));
        v[end].push_back(make_pair(st, val));
    }
    cin >> v1 >> v2;

    // 시작점 1에서 부터 v1, v2까지 최단 거리
    dijkstra(1);
    start1 = dist[v1];
    start2 = dist[v2];

    // v1부터 v2까지의 최단거리와, v1부터 n까지의 최단거리
    dijkstra(v1);
    start1 += dist[v2];
    start2 += dist[v2];
    v1_n = dist[n];

    dijkstra(v2);
    v2_n = dist[n];

    int answer=INF;

    answer = min(answer, start1 + v2_n);
    answer = min(answer, start2 + v1_n);

    if(answer == INF) cout << -1 << endl;
    else cout << answer << endl;
}