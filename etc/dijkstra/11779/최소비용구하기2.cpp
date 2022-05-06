#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

int n, m;
int src, destination;
long long dist[1001];

vector<pair<int, int> > v[1001];
vector<int> route;
vector<int> visited[1001];
int cnt = 0;
int prev_num[1001];

void dijkstra(int idx) {
    priority_queue<pair<int, long long>, vector<pair<int, long long> >, greater<pair<int, long long> > > pq;
    dist[idx] = 0;
    pq.push(make_pair(idx, 0));
    while(!pq.empty()) {
        int cur = pq.top().first;
        long long cost = pq.top().second;
        pq.pop();
        if(cost > dist[cur]) continue;
        for(int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            long long nCost = v[cur][i].second;
            if(dist[next] > cost + nCost) {
                dist[next] = cost + nCost;
                pq.push(make_pair(next, dist[next]));
                prev_num[next] = cur;
            }
        }
    }
}

void print_route(int node, int idx) {
    cnt++;
    if(node == src) {
        cout << cnt << '\n';
        cout << node << ' ';
        return;
    }
    print_route(prev_num[node], idx+1);
    cout << node << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i <= n; i++) {
        dist[i] = INF;
    }
    for(int i = 0; i < m; i++) {
        int start, end, val;
        cin >> start >> end >> val;
        v[start].push_back(make_pair(end, val));
    }
    cin >> src >> destination;
    // visited[destination].push_back(src);
    dijkstra(src);
    cout << dist[destination] << '\n';
    print_route(destination, 0);
}