#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[2200][2200];
int paper_num[3];  // -1, 0, 1의 개수
bool check_paper(int x, int y, int z) {
	// 모두 같은 숫자인지 확인
	int num = arr[x][y];
	for (int i = 0; i < z; i++) {
		for (int j = 0; j < z; j++) {
			if (arr[x + i][y + j] != num) {
				return false;
			}
		}
	}
	return true;
}

void solution(int x, int y, int num) {
	if (check_paper(x, y, num)) {
		paper_num[arr[x][y]+1] += 1; // 인덱스 (0 / 1 / 2) == (-1 / 0 / 1)
		return;
	}
	// 모두 같지 않다면 3으로 나눠 분할하여 확인
	int div = num / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solution(x + i * div, y + j * div, div);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solution(0, 0, n);
	for (int i = 0; i < 3; i++) {
		cout << paper_num[i] << endl;
	}
}