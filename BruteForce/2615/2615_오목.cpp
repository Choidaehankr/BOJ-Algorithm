#include <iostream>
#include <vector>
using namespace std;

int board[20][20];
vector<pair<int, int>> loc;
int cnt = 1;
int dx[4] = { -1, 0, 1, 1 };  // 오른쪽 위, 오른쪽, 오른쪽 아래, 아래
int dy[4] = { 1, 1, 1, 0 };
int res_x = 0, res_y = 0;

bool solution(int x, int y, int team) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int cnt = 1;
		while (1) {
			if (nx < 0 || nx >= 19 || ny < 0 || nx > 19 || board[nx][ny] != team) // 종료 조건
				break;
			cnt += 1;
			nx = nx + dx[i];
			ny = ny + dy[i];
		}
		if (cnt == 5) {  // 오목이 됐을 때, 시작 좌표를 기준으로 현재 확인방향의 반대로 1칸을 확인해 육목인지 확인
			int check_x = x - dx[i];
			int check_y = y - dy[i];
			if (check_x >= 0 && check_x < 19 && check_y >= 0 && check_y < 19) {
				if (board[check_x][check_y] == team)  // 육목일 경우 continue
					continue;
			}
			res_x = x+1;  // 현재 좌표를 결과 값에 저장후 return
			res_y = y+1;
			return true;
		}
	}
	return false;
}

int main() {
	vector<pair<int, int>> b_team;  // 검/흰 돌의 좌표를 담을 vector
	vector<pair<int, int>> w_team;
	bool b_win = false, w_win = false;

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				b_team.push_back({ i, j });
			}
			else if (board[i][j] == 2) {
				w_team.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < b_team.size(); i++) {
		int x = b_team[i].first;
		int y = b_team[i].second;
		if (solution(x, y, 1)) {
			b_win = true;
			break;
		}
	}
	for (int i = 0; i < w_team.size(); i++) {
		int x = w_team[i].first;
		int y = w_team[i].second;
		if (solution(x, y, 2)) {
			w_win = true;
			break;
		}
	}
	if (b_win) {
		cout << 1 << endl;
		cout << res_x << ' ' << res_y;
	}
	else if (w_win) {
		cout << 2 << endl;
		cout << res_x << ' ' << res_y;
	} 
	else if (!b_win && !w_win) {
		cout << 0 << endl;  // 아직 승부가 나지 않은 경우
	}
}