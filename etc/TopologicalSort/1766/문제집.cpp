#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 32001
#define endl '\n'
using namespace std;

int n, m;
int income[MAX];
vector <int> v[MAX];
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    cin >> n >> m;
    // 진입 간선을 0으로 초기화 (사실 필요 없음)
    for(int i = 1; i <= n; i++) {
        income[i] = 0;
    }
    for(int i = 0; i < m; i++) {
        int first, end;
        cin >> first >> end;
        v[first].push_back(end);
        income[end]+=1;
    }
    for(int i = 1; i <= n; i++) {
        if(income[i] == 0) {
            pq.push(i);  // 진입간선이 없는 문제를 난이도의 오름차순으로 pq에 push.
        }
    }
    while(!pq.empty()) {
        int cur = pq.top();
        cout << cur << ' ';
        pq.pop();
        for(int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            income[next] -= 1;
            if(income[next] == 0) {
                pq.push(next);
            }
        }
    }
}