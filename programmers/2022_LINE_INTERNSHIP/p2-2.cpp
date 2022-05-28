#include <string>
#include <vector>
#include<algorithm>
#include <queue>
#include <iostream>

using namespace std;

int dx[1000001];
bool visited[1000001];
int answer = 0;

int len = 0;
int bfs(int x, int dest, vector<int> v) {
    int result = 1000000*2000;
    queue<pair<int, int> > q;
    q.push(make_pair(x, 0));  // 현재 종이는 x개, 소요 시간은 0
    while(!q.empty()) {
        int cur_x = q.front().first;
        int cnt = q.front().second;
        // 현재 잘려진 종이의 개수가 cur_x 일 때, 소요시간의 최솟값 갱신
        if(cur_x == dest) {
            result = min(result, cnt);
        }
        visited[cur_x] = true;  // 방문 체크
        q.pop();
        // 종이를 자를 경우, 종이의 개수는 i 만큼, 시간은 dx[i] 만큼 증가함
        for(int i = 1; i <= len; i++) {  
            int nx = cur_x + i;
            int nCnt = cnt + dx[i];
            if(nx > dest || visited[nx] || i > cur_x) {
                continue;
            }
            q.push(make_pair(nx, nCnt));
        }
    }
    return result;
}

int solution(int n, vector<int> times) {
    len = times.size();
    // [1개 잘랐을 때: times[0] 소요, 2개 잘랐을 때: times[1] 소요] 와 같이 처리하기 위함
    for(int i = 0; i < times.size(); i++) {
        dx[i+1] = times[i];
    }
    answer = bfs(1, n, times);  // 현재 종이는 1개이고 총 n개 만드는 게 목표
    return answer;
}