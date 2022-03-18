#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char battleGround[101][101];
int N, M;


long long int solution(int x, int y, int c) {
    long long int cnt = 0;
    queue<pair<int, int>> q;
    battleGround[x][y] == 'X';  // 'X'로 방문 체크
    q.push({x, y});
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N || battleGround[nx][ny] != c)
                continue;
            battleGround[nx][ny] = 'X';
            cnt++;
            q.push({nx, ny});
        }
    }
    if (cnt == 0) return 1;
    else return cnt*cnt;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        string str; cin >> str;
        for(int j = 0; j < N; j++) {
            battleGround[i][j] = str[j];
        }
    }
    int res = 0;
    long long int whiteNum = 0, blueNum = 0;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            char c = battleGround[i][j];
            if(c == 'W') {
                whiteNum += solution(i, j, c);
            } else if(c == 'B') {
                blueNum += solution(i, j, c);
            }
        }
    }
    cout << whiteNum << ' ' << blueNum;    
}
