#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e8
using namespace std;

vector<pair<int, int> > v[5001];
long long dist[5001];
int prev_num[5001];

void dfs(int src, int dest, int cost) {
    if(src == dest) return;

}

vector<int> solution(int n, vector<vector<int> > paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
     for(int i = 0; i < paths.size(); i++) {
        int start = paths[i][0];
        int end = paths[i][1];
        int val = paths[i][2];
        v[start].push_back(make_pair(end, val));
        v[end].push_back(make_pair(start, val));
    }
    for(int i = 0; i < gates.size(); i++) {
        for(int j = 0; j < summits.size(); j++) {
            dfs(gates[i], summits[i], 0);
        }
    }
    return answer;
}

void solve(int num) {
    priority_queue<pair<int, long long>, vector<pair<int, long long> >, greater<pair<int, long long> > > pq;
    dist[num] = 0;
    pq.push(make_pair(num, 0));
    while(!pq.empty()) {
        int cur = pq.top().first;
        long long cost = pq.top().second;
        pq.pop();
        if(cur == 5) break;
        if(cost > dist[cur]) continue;
        for(int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            long long nCost = v[cur][i].second;
            if(dist[next] > nCost) {
                dist[next] = nCost;
                pq.push(make_pair(next, dist[next]));
                prev_num[next] = cur;
          }
        }
    }
}

// vector<int> solution(int n, vector<vector<int> > paths, vector<int> gates, vector<int> summits) {
//     vector<int> answer;
//     for(int i = 1; i <= n; i++) {
//         dist[i] = INF;
//     }
//     for(int i = 0; i < paths.size(); i++) {
//         int start = paths[i][0];
//         int end = paths[i][1];
//         int val = paths[i][2];
//         v[start].push_back(make_pair(end, val));
//         v[end].push_back(make_pair(start, val));
//     }
//     // for(int i = 0; i < gates.size(); i++) {
//     //     int src = gates[i];
//     //     solve(src);
//     // }
//     solve(1);
//     cout << "solution" << endl;
//     for(int i = 1; i <= n; i++) {
//         cout << dist[i] << ' ';
//     }
//     return answer;
// }

int main() {
    int n; 
    cin >> n;
    vector<vector<int> > v;
    for(int i = 0; i < 8; i++) {
        vector<int> tmp;
        int start, end, val;
        cin >> start >> end >> val;
        tmp.push_back(start);
        tmp.push_back(end);
        tmp.push_back(val);
        v.push_back(tmp);
    }
    vector<int> g;
    g.push_back(1); g.push_back(3);
    vector<int> s;
    s.push_back(5);
    vector<int> result = solution(n, v, g, s);
}