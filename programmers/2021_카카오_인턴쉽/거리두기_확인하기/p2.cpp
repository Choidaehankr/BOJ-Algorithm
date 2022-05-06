#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[5][5];

bool bfs(int x, int y, vector<string> v, int cnt) {
    // queue<pair<pair<int, int>, int> > q;
    queue<pair<int, int> > q;
    // q.push(make_pair(make_pair(x, y), 0));
    q.push(make_pair(x, y));
    visited[x][y] = true;
    while(!q.empty()) {
        // x = q.front().first.first;
        // y = q.front().first.second;
        x = q.front().first;
        y = q.front().second;
        // int cnt = q.front().second;
        q.pop();
        if(cnt > 2) break;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visited[nx][ny] || v[nx][ny] == 'X') continue;
            if(v[nx][ny] == 'P' && cnt <= 2) return true;
            q.push(make_pair(make_pair(nx, ny), cnt+1));
            visited[nx][ny] = true;
        }
    }
}

bool solve(vector<string> v) {
    vector<pair<int, int> > loc;
    bool flag = false;
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            if(v[i][j] == 'P') {
                loc.push_back(make_pair(i, j));
            }
        }
    }
    for(int i = 0; i < loc.size(); i++) {
        flag = false;
        memset(visited, false, sizeof(visited));
        bfs(loc[i].first, loc[i].second, v, 0);
        if(flag) return false;
    }
    return true;
}

// bool bfs(vector<string> v, int x, int y) {
//     queue<pair<pair<int, int>, int > > q;
//     q.push(make_pair(make_pair(x, y), 0));
//     bool flag = false;
//     visited[x][y] = true;
//     int start_x = x, start_y = y;
//     while(!q.empty()) {
//         x = q.front().first.first;
//         y = q.front().first.second;
//         int cnt = q.front().second;
//         q.pop();
//         for(int i = 0; i < 4; i++) {
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visited[nx][ny] || v[nx][ny] == 'X') continue;
//             if(v[nx][ny] == 'P') {
//                 if(cnt <= 2) {
//                     return false;
//                 }
//             }
//             q.push(make_pair(make_pair(nx, ny), cnt+1));
//             visited[nx][ny] = true;
//         }
//     }
//     return true;
// }

vector<int> solution(vector<vector<string> > places) {
    vector<int> answer;
    for(int i = 0; i < places.size(); i++) {
        if(solve(places[i])) answer.push_back(1);
        else answer.push_back(1);
    }
    return answer;
}

int main() {
    vector<vector<string> > v;
    for(int i = 0; i < 5; i++) {
        vector<string> tmp;
        for(int j = 0; j < 5; j++) {
            string str; cin >> str;
            tmp.push_back(str);
        }
        v.push_back(tmp);
        tmp.clear();
    }
    vector<int> result = solution(v);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    // for(int i = 0; i < v.size(); i++) {
    //     cout << "[" << i << "] th vector" << endl;
    //     for(int j = 0; j < v[i].size(); j++) {
    //         cout << v[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}