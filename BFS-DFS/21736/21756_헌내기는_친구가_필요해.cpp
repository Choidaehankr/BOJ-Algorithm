#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dx[4] = {1, 0, -1, 0};  // (상, 하, 좌, 우) 4방향 탐색
int dy[4] = {0, 1, 0, -1};
int N, M, x, y;
char campus[601][601];

int bfs(int x, int y) {
    int cnt = 0;
    queue<pair<int, int>> q;
    campus[x][y] = 'X';  // 배열에 'X' 표시를 해주며 방문 표시.
    q.push({x, y});
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M || campus[nx][ny] == 'X')
                continue;
            else {
                if(campus[nx][ny] == 'P') {  // 사람을 만났다면 cnt 변수 증가
                    cnt++;
                }
                q.push({nx, ny});  // 다음 탐색을 위해 queue에 push
                campus[nx][ny] = 'X';  // 마찬가지로 방문 표시
            }
        }
    }
    if(cnt == 0) {  // 만난 사람이 없다면 -1을 return
        return -1;
    } else return cnt;
}
int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < str.size(); j++) {
            campus[i][j] = str[j];
            if(campus[i][j] == 'I') {
                x = i, y = j;
            }
        }
    }

    int result = bfs(x, y);

    if(result != -1) cout << result << endl;
    else cout << "TT" << endl;  // 만난 사람이 없다면 TT 출력
}