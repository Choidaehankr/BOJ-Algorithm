#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int board[9][9];
void printBoard();
bool checkAround(int x, int y, int num);
void solution(int idx);
vector<pair<int, int> > v;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    string str;
    for(int i = 0; i < 9; i++) {
        cin >> str;
        for(int j = 0; j < 9; j++) {
            board[i][j] = str[j] - '0';
            if(board[i][j] == 0) {
                v.push_back(make_pair(i, j));
            }
        }
    }
    solution(0);
    return 0;
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


bool checkAround(int x, int y, int num) {
    for(int i = 0; i < 9; i++) {
        if(i == x) continue;
        if(board[i][y] == num)
            return false;
    }
    for(int i = 0; i < 9; i++) {
        if(i == y) continue;
        if(board[x][i] == num)
            return false;
    }
    int dx, dy;
    int tx = x + 1, ty = y + 1;

    if (tx%3 == 0) dx = tx / 3;
    else dx = tx / 3 + 1;
    if(ty % 3 == 0) dy = ty / 3;
    else dy = ty / 3 + 1;

    dx *= 3, dy *= 3;

    for(int i = dx-3; i < dx; i++) {
        for(int j = dy-3; j < dy; j++) {
            if(i == x && j == y) continue;
            if(board[i][j] == num) return false;
        }
    }
    return true;
}

void printBoard() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}
