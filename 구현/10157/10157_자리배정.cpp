#include <iostream>
#define MAX 1001
using namespace std;

int width, height, K;
int cnt = 1;

int arr[MAX][MAX];

int dx[4] = {-1, 0, 1, 0};  // 상, 우, 하, 좌 (시계방향 탐색)
int dy[4] = {0, 1, 0, -1};
int dir = 0;  // 위부터 탐색

int main() {
    cin >> width >> height >> K;
    if(K > width * height) {  // 좌석을 배정할 수 없는 경우.
        cout << 0 << endl;
        return 0;
    }
    int x = height, y = 1;  // 탐색 시작 위치
    arr[x][y] = cnt;
    while(1) {
        if(cnt == K) {
            cout << y << ' ' << height-x+1 << endl;
            break;  // 종료
        }
        if(dir == 4)  {  // 시계방향 탐색을 마쳤으면, 탐색 방향을 0 (북)으로 초기화.
            dir = 0;
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 1 || ny < 1 || nx > height || ny > width || arr[nx][ny] != 0) {
            dir+=1;  // 해당 방향에 가능한 모든 자리를 배정했으면 방향 전환.
            continue;
        }
        arr[nx][ny] = cnt+=1;
        x = nx; y = ny;
    }
}