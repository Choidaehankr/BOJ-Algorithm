#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int r, c, n;

char arr[150][150];
bool visited[150][150];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int x, y;
int direction;

void drop_mineral(vector<pair<int, int> > v) {
    int num = v[0].first;
    int result = r - num;
    for(int i = 0; i < v.size(); i++) {
        int nx = v[i].first;
        int cnt = 0;
        for(int j = nx+1; j <= r; j++) {
            if(arr[j][v[i].second] == 'x' && !visited[j][v[i].second]) {
                result = min(cnt, result);
                break;
            }
            cnt++;
        }
    }
    for(int i = 0; i < v.size(); i++) {
        int mx = v[i].first, my = v[i].second;
        arr[mx+result][my] = 'x';
        arr[mx][my] = '.';
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    // 행이 가장 큰 것 (바닥과 가까운 것) 순으로 정렬
    return a.first > b.first;
}


void check_mineral(int tx, int ty) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int> > q;
    vector<pair<int, int> > cluster;
    bool flag = false;
    visited[tx][ty] = true;
    q.push(make_pair(tx, ty));
    while(!q.empty()) {
        tx = q.front().first;
        ty = q.front().second;
        if(arr[tx][ty] == 'x') cluster.push_back(make_pair(tx, ty));
        q.pop();
        if(tx == r) {
            flag = true;
        }
        for(int i = 0; i < 4; i++) {
            int nx = tx + dx[i];
            int ny = ty + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= r && ny <= c && !visited[nx][ny] && arr[nx][ny] == 'x') {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
    if(!flag) {
        if(!cluster.empty()) {
            sort(cluster.begin(), cluster.end(), cmp);
            drop_mineral(cluster);
        }
    }
    cluster.clear();
}

int tmp_x = 0;

int throw_stick(int dir, int height) {
    int h = tmp_x = r - height + 1;
    if(dir % 2 == 0) {  // 왼쪽
        for(int i = 1; i <= c; i++) {
            if(arr[h][i] == 'x') {
                arr[h][i] = '.';
                return i;  // 미네랄이 부서진 열의 인덱스를 return
            }
        }
    } else {  // 오른쪽
        for(int i = c; i >= 1; i--) {
            if(arr[h][i] == 'x') {
                arr[h][i] = '.';
                return i;
            }
        }
    }
    return -1;
}

void solution(int dir, int height) {
    int idx = throw_stick(dir, height);
    direction = dir;
    vector<pair<int, int> > tmp;
    if(idx != -1) {
        for(int i = 0; i < 4; i++) {  // 위에 검사할 필요 있나?
            int nx = tmp_x + dx[i];
            int ny = idx + dy[i];
            if(nx < 1 || ny < 1 || nx > r || ny > c) continue;
            if(arr[nx][ny] == 'x') {
                tmp.push_back(make_pair(nx, ny));
            }
        }
        for(int i = 0; i < tmp.size(); i++) {
            check_mineral(tmp[i].first, tmp[i].second);
        }
    }
    tmp.clear();
}

int main() {
    cin >> r >> c;
    for(int i = 1; i <= r; i++) {
        string str; cin >> str;
        for(int j = 0; j < str.size(); j++) {
            arr[i][j+1] = str[j];
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        solution(i, num);
    }
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cout << arr[i][j];
            if(i == r && j == c)  {
                continue;
            }
        }
        cout << endl;
    }
}