#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;

int answer = 0;

void dfs(int idx, int sheep, int wolf, vector<int> v, queue<int> q) {
    if(v[idx] == 0) {
        sheep += 1;
    } else {
        wolf += 1;
    }
    // 종료 조건
    // 해당 위치를 방문하면 안되는 것이 아니라, 다른 곳을 먼저 방문해서 양을 모은 뒤 재방문 해야 함.
    if(wolf >= sheep) {
        return;
    }
    // 양의 최대 수 갱신
    answer = max(answer, sheep);
    
    for(int i = 0; i < graph[idx].size(); i++) {
        q.push(graph[idx][i]);  // 현재 노드에서 방문할 수 있는 노드를 queue에 push
    }
    
    for(int i = 0; i < q.size(); i++) {
        int next = q.front();
        q.pop();
        dfs(next, sheep, wolf, v, q);
        q.push(next);  // 종료 조건에 의해 다시 방문해야 할 노드
    }
}

// info: 몇번 노드가 양/늑대 정보인지 정보
// edges: 간선 정보

int solution(vector<int> info, vector<vector<int>> edges) {
    graph.resize(info.size(), vector<int> ()); // 2차원 벡터 초기화
    
    for(int i = 0; i < edges.size(); i++) {
        // 현재 노드와 연결된 노드를 저장
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    
    queue<int> que;  // 방문할 수 있는 노드를 저장해두는 큐

    // 시작점, 양, 늑대, 정보, 큐
    dfs(0, 0, 0, info, que);
    return answer;
}