#include <iostream>
#include <string>
#include <vector>
using namespace std;

int board[10][10];
void printBoard();
bool checkAround(int x, int y, int num);
void solution(int idx);
vector<pair<int, int> > v;


void printBoard() {
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

bool checkAround(int x, int y, int num) {
    for(int i = 1; i <= 9; i++) {
        if(i == x || i == y) continue;
        if(board[i][y] == num || board[x][i] == num)
            return false;
    }
    // for(int i = 1; i <= 9; i++) {
    //     if(i == x) continue;
    //     if(board[i][y] == num)
    //         return false;
    // }
    // for(int i = 1; i <= 9; i++) {
    //     if(i == y) continue;
    //     if(board[x][i] == num)
    //         return false;
    // }
    // int dx, dy;
    // int tx = x + 1, ty = y + 1;
    // if (tx%3 == 0) dx = tx / 3;
    // else dx = tx / 3 + 1;

    // if(ty % 3 == 0) dy = ty / 3;
    // else dy = ty / 3 + 1;
    // dx *= 3, dy *= 3;
    // for(int i = dx-3; i < dx; i++) {
    //     for(int j = dy-3; j < dy; j++) {
    //         if(i == x && j == y) continue;
    //         if(board[i][j] == num) return false;
    //     }
    // }
    // return true;
    int tx, ty; // 3×3 크기의 보드에 중복 없는지 확인
    if(x%3 == 0) tx = x/3;
    else tx = x/3+1;
    if(y%3 == 0) ty = y/3;
    else ty = y/3+1;
    tx *= 3, ty *= 3;
    for(int i=tx-2; i<=tx; i++){
        for(int j=ty-2; j<=ty; j++){
            if(i == x && j == y) continue;
            if(board[i][j] == num) return false;
        }
    }
    return true;
}

void solution(int idx) {
    if(idx == v.size()) {
        printBoard();
        exit(0);
    }
    int x = v[idx].first;
    int y = v[idx].second;
    for(int i = 1; i <= 9; i++) {
        if(checkAround(x, y, i)) {
            board[x][y] = i;
            solution(idx+1);
            board[x][y] = 0;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    string str;
    for(int i = 1; i <= 9; i++) {
        cin >> str;
        for(int j = 0; j < 9; j++) {
            board[i][j+1] = str[j] - '0';
            if(board[i][j+1] == 0) {
                v.push_back(make_pair(i, j+1));
            }
        }
    }
    solution(0);
    return 0;
}
