#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int len = 0;
vector<string> grid;
vector<string> tmp;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
bool visited[10][10];
int solution(vector<string> v) {
    int answer = -1;
    return answer;
}

// int bfs(int x, int y, char val) {
//     memset(visited, false, sizeof(visited));
//     tmp[x][y] = val;
//     int cnt = 0;
//     queue<pair<int, int> > q;
//     q.push(make_pair(x, y));
//     visited[x][y] = true;
//     while(!q.empty()) {
//         x = q.front().first;
//         y = q.front().second;
//         q.pop();
//         for(int i = 0; i < 4; i++) {
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             if(nx >= 0 && ny >= 0 && nx < len && ny < len && !visited[nx][ny]) {
//                 if(tmp[nx][ny] == '?' || grid[nx][ny] == val) {
//                     q.push(make_pair(nx, ny));
//                     visited[nx][ny] = true;
//                 }
//             }
//         }
//     }

//     for(int i = 0; i < grid.size(); i++) {
//         for(int j = 0; j < grid[i].size(); j++) {
//             //if((grid[i][j] == '?' || grid[i][j] == val) && !visited[i][j])
//             if(grid[i][j] == val && !visited[i][j])
//                 return 0;
//         }
//     }
//     return 1;
// }


int bfs(int x, int y, char val) {
    cout << "x: " << x << " y: " << y << " val: " << val << endl;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y = dy[i];
            cout << "nx is " << nx << " ny is " << ny << endl;
            if(nx >= 0 && ny >= 0 && nx < 3 && ny < 3 && !visited[nx][ny]) {
                if(tmp[nx][ny] == val || tmp[nx][ny] == '?') {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        } 
    }
    for(int i = 0; i < tmp.size(); i++) {
        for(int j = 0; j < tmp[i].size(); j++) {
            if(!visited[i][j] && tmp[i][j] != val) {
                cout << "---2nd search---" << endl;
                bfs(i, j, tmp[i][j]);
            }
        }
    }
    for(int i = 0; i < tmp.size(); i++) {
        for(int j = 0; j < tmp[i].size(); j++) {
            if(!visited[i][j])
                return 0;
        }
    }
    memset(visited, false, sizeof(visited));
    return 1;
}

// int solution(int x, int y, int val) {
//     tmp[x][y] = val;  // 다시 상태 돌려줘야함
//     visited[x][y] = true;
//     int cnt = 0;
//     for(int i = 0; i < tmp.size(); i++) {
//         for(int j = 0; j < tmp[i].size(); j++) {
//             if(tmp[i][j] != '?' && !visited[i][j]) {
//                 cnt += bfs(i, j, tmp[i][j]);
//             }
//         }
//     }
// }
vector<pair<int, int> > loc;  // '?'의 위치

int main() {
    int cnt = 0;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        grid.push_back(str);
        tmp.push_back(str);
        cout << "str: " << str <<endl;
    }
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++) {
            if(grid[i][j] == '?') {
                loc.push_back(make_pair(i, j));
                cout << "location, i: " << i << " j: " << j << endl;
            }
        }
    }
    for(int i = 0; i < loc.size(); i++) {
        int nx = loc[i].first;
        int ny = loc[i].second;
        tmp[nx][ny] = 'a';
        visited[nx][ny] = true;
        cnt += bfs(nx, ny, 'a');
        tmp[nx][ny] = 'b';
        visited[nx][ny] = true;
        cnt += bfs(nx, ny, 'b');
        tmp[nx][ny] = 'c';
        visited[nx][ny] = true;
        cnt += bfs(nx, ny, 'c');
        tmp[nx][ny] = '?';
    }
    cout << "cnt is " << cnt << endl;
}