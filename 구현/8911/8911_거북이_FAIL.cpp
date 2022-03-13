#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

// 시간초과

int arr[1002][1002];

int dx[4] = {-1, 0, 1, 0};  // 북 동 남 서
int dy[4] = {0, 1, 0, -1};

int turn_left(int dir) {
    if(dir != 0) return dir-1;
    else return 3;
}

int turn_right(int dir) {
    if(dir != 3)
        return dir+1;
    else
        return 0;
}

bool check_range(int x, int y) {
    if(x < 0 || y < 0 || x > 1002 || y > 1002)
        return false;
    else return true;
}

void move(string cmd) {
    int dir = 0;
    int x = 500, y = 500;  // 시작 좌표
    int nx, ny, ndir;
    for(int i = 0; i < cmd.size(); i++) {
        char c = cmd[i];
        switch (c)
        {
        case 'F':
            nx = x + dx[dir];
            ny = y + dy[dir];
            if(!check_range(nx, ny)) {
                continue;
            }
            arr[nx][ny] = 1;
            break;
        case 'B':
            nx = x - dx[dir];
            ny = y - dy[dir];
            if(!check_range(nx, ny)) {
                continue;
            }
            arr[nx][ny] = 1;
            break;
        case 'L':
            if(dir != 0) {
                dir--;
            } else {
                dir = 3;
            }
            break;
        case 'R':
            if(dir != 3) {
                dir++;
            } else {
                dir = 0;
            }
            break;
        default:
            break;
        }
        // if(cmd[i] == 'F') {
        //     nx = x + dx[dir];
        //     ny = y + dy[dir];
        //     if(!check_range(nx, ny)) {
        //         continue;
        //     }
        //     arr[nx][ny] = 1;
        // } else if(cmd[i] == 'B') {
        //     nx = x - dx[dir];
        //     ny = y - dy[dir];
        //     if(!check_range(nx, ny)) {
        //         continue;
        //     }
        //     arr[nx][ny] = 1;
        // } else if(cmd[i] == 'L') {
        //     if(dir != 0) {
        //         dir--;
        //     } else {
        //         dir = 3;
        //     }
        //     // dir = turn_left(dir);
        // } else if(cmd[i] == 'R') {
        //     if(dir != 3) {
        //         dir++;
        //     } else {
        //         dir = 0;
        //     }
        //     // dir = turn_right(dir);
        // }
        x = nx; y = ny;
    }
}

int get_area() {
    int max_x = 500, max_y = 500;
    // int min_x = 500, min_y = 500;
    int min_x = 500, min_y = 500;
    int result = 0;
    // for(int i = 0; i < 1000; i++) {
    //     for(int j = 0; j < 1000; j++) {
    for(int i = 0; i < 1002; i++) {
        for(int j = 0; j < 1002; j++) {
            if(arr[i][j] == 1) {
                max_x = max(max_x, i);
                max_y = max(max_y, j);
                min_x = min(min_x, i);
                min_y = min(min_y, j);
            }
        }
    }
    // cout << "max_x " << max_x << " max_y " << max_y << "min_x " << min_x << " min_y " << min_y << endl;
    return (max_x - min_x) * (max_y - min_y);
}

void print_arr() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test_case;
    // cin >> test_case;
    scanf("%d", &test_case);
    while(test_case--) {
        string cmd;
        cin >> cmd;
        // scanf("%s", &cmd);
        move(cmd);
        //print_arr();
        // cout << get_area() << endl;
        printf("%d\n", get_area());
        memset(arr, 0, sizeof(arr));
    }
}