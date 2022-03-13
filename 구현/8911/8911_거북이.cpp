#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 0, 1, 0};  // dxdy[0]: 북, dx[1]: 동, dx[2]: 남, dx[3]: 서
int dy[4] = {0, 1, 0, -1};

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        string cmd;
        cin >> cmd;
        int x = 0, y = 0, dir = 0, nx = 0, ny = 0;
        int max_x = 0, max_y = 0, min_x = 0, min_y = 0;
        for(int i = 0; i < cmd.size(); i++) {
            char c = cmd[i];
            if(c == 'L') {  // 왼쪽으로 회전. dx, dy의 인덱스가 1씩 감소. 0(북)일때는 3(서)
                if(dir != 0) dir--;
                else dir = 3;
                continue;
            } else if(c == 'R') {  // 오른쪽으로 회전. dx, dy의 인덱스가 1씩 증가. 3(서)일때는 0(북)
                if(dir != 3) dir++;
                else dir = 0;
                continue;
            } else if(c == 'F') {  // dx, dy 방향으로 전진
                nx = x + dx[dir];  
                ny = y + dy[dir];
            } else if(c == 'B') {  // dx, dy 방향으로 후진
                nx = x - dx[dir];
                ny = y - dy[dir];
            }
            max_x = max(max_x, nx);  // 넓이를 구하기 위해 x, y 좌표의 최대/최소값 갱신
            max_y = max(max_y, ny);
            min_x = min(min_x, nx);
            min_y = min(min_y, ny);
            x = nx, y = ny;  // 다음 이동을 위하여 거북이 위치 갱신
        }
        cout << (max_x - min_x) * (max_y - min_y) << endl;
    }
    
}