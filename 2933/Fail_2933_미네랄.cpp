#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int r, c, n;

char arr[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> v;
int x, y;
int direction;

void drop_mineral(vector<pair<int, int> > v) {
    cout << "before drop mireral!! " << endl;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    for(int k = 0; k < v.size(); k++) {
        int nx = v[k].first, ny = v[k].second;
        for(int i = nx+1; i <= r; i++) {
            if(arr[i][ny] == 'x') {
                arr[nx][ny] = '.';
                arr[i-1][ny] = 'x';
                break;
            } else if(arr[i][ny] == '.') {
                arr[nx][ny] = '.';
                arr[i][ny] = 'x';
                break;
            }
        }
    }
    cout << "drop() check" << endl;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "end!!!!!!!!" << endl;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    // 행이 가장 큰 것 (바닥과 가까운 것) 순으로 정렬
    return a.first > b.first;
}

bool visited[101][101];

void check_mineral(int x, int y) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int> > q;
    vector<pair<int, int> > cluster;
    // if(direction % 2 == 0) {
    //     y = y + 1;
    // } else {
    //     y = y - 1;
    // }
    for(int i = 1; i < 4; i++) {  // 아래 제외 3방향 탐색
        int mx = x + dx[i];
        int my = y + dy[i];
        if(arr[mx][my] == 'x') {
            x = mx; y = my;
            cout << "find!!!!!!!!!!!! " << x << ' ' << y << endl;
            break;
        }
    }
    bool flag = false;
    visited[x][y] = true;
    q.push(make_pair(x, y));
    // visited[1][1] = true;
    // q.push(make_pair(1, 1));
    while(!q.empty()) {
        int cnt = 0;
        x = q.front().first;
        y = q.front().second;
        if(arr[x][y] == 'x') cluster.push_back(make_pair(x, y));
        q.pop();
        //cout << "x: " << x << " y: " << y << endl;
        if(x == r) {
            flag = true;
        }
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // if(nx < 1 || ny < 1 || nx > r || ny > c || visited[nx][ny]) {
            //     cout << "it will be continue,,, nx: " << nx << " ny: " << ny << endl;
            //     continue;
            // }
            if(nx >= 1 && ny >= 1 && nx <= r && ny <= c && !visited[nx][ny] && arr[nx][ny] == 'x') {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
    if(!flag) {
        sort(cluster.begin(), cluster.end(), cmp);
        drop_mineral(cluster);
    }
}

int throw_stick(int dir, int height) {
    int h = x = r - height + 1;
    cout << "dir: " << dir << " height: " << height <<  " [h]: " << h << endl;
    if(dir % 2 == 0) {  // 왼쪽
        for(int i = 1; i <= c; i++) {
            if(arr[h][i] == 'x') {
                arr[h][i] = '.';
                return i;
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
    if(idx != -1) {
        check_mineral(x, idx);  // bfs 탐색을 위해 미네랄이 파괴된 (x, y) 좌표를 얻음. 
    }
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

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
}