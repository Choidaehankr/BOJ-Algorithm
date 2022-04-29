#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int R, C, M;
// 1: 위, 2: 아래, 3: 오른쪽, 4: 왼쪽
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

struct Shark {
    int speed;
    int dir;
    int size;
};
vector<Shark> arr[101][101];
int sum = 0;

// 낚시왕 이동, 걍 y축 이동하면 됨.
// y축에서 잡을 수 있는 상어 확인 후 잡음
// 상어 이동. 
// 이동할때 위치 확인
// 이동 후 잡아먹히는 상어 확인.


bool cmp(Shark a, Shark b) {
    return a.size > b.size;
} 

void move_shark() {
    vector<Shark> tmp[102][102];
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            int x = i, y = j;
            if(!arr[i][j].empty()) {
                Shark shark;
                int d = arr[i][j][0].dir, s = arr[i][j][0].speed, z = arr[i][j][0].size;
                if (d == 1 || d == 2) {
                    int loc = 2 * (R-1);
                    if (s >= loc) s = s % loc;
                    for(int k = 0; k < s; k++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if(nx < 1) {
                            d = 2;
                            nx += 2;
                        } else if (nx > R) {
                            d = 1;
                            nx -= 2;
                        }
                        x = nx; y = ny;
                    }
                } else if(d == 3 || d == 4) {
                    int loc = 2 * (C-1);
                    if (s >= loc) s = s % loc;
                    for(int k = 0; k < s; k++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if(ny < 1) {
                            d = 3;
                            ny += 2;
                        } else if (ny > C) {
                            d = 4;
                            ny -= 2;
                        }
                        x = nx; y = ny;
                    }
                }
                shark.dir = d, shark.speed = s, shark.size = z;
                tmp[x][y].push_back(shark);
            }
        }
    }
    // 중복 상어 먹어버리기
    for(int i = 0; i <= R; i++) {
        for(int j = 0; j <= C; j++) {
            if(tmp[i][j].size() > 1) {
                sort(tmp[i][j].begin(), tmp[i][j].end(), cmp);
                while(tmp[i][j].size() >= 2) {
                    tmp[i][j].pop_back();
                }
            }
        }
    }
    // tmp를 a에 복사
    for(int i = 0; i <= R; i++) {
        for(int j = 0; j <= C; j++) {
            arr[i][j].clear();
            if(!tmp[i][j].empty()) {
                arr[i][j].push_back(tmp[i][j][0]);
            }
        }
    }
}

int get_shark(int idx) {
    // 같은 열 땅과 제일 가까운 (맨 위) 상어를 잡음
    for(int i = 1; i <= R; i++) {
        if(!arr[i][idx].empty()) {
            int res = arr[i][idx].front().size;
            arr[i][idx].clear();
            return res;
        }
    }
    return 0;
}

// 낚시왕의 위치 (0, 1) ~ (0, C)
void solution(int x, int y) {
    sum += get_shark(y);
    move_shark();
}

int main() {
    cin >> R >> C >> M;
    if(M == 0) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < M; i++) {
        Shark shark;
        int x, y, s, d, z;
        cin >> x >> y >> s >> d >> z;
        shark.speed = s, shark.dir = d, shark.size = z;
        arr[x][y].push_back(shark);
    }
    for(int i = 1; i <= C; i++) {
        solution(0, i);
    }
    cout << sum << endl;
}