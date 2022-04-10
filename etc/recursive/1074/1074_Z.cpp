#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int N, R, C;
int cnt = 0;
int recursive(int n, int x, int y) {
	if (n < 1) return 0;

	int flag = int(pow(2, N - 1));

	if (x < flag && y < flag) {
		return recursive(n - 1, x, y);
	}
	else if (x < flag && y >= flag) {
		return flag * flag + recursive(n - 1, x, y - flag);
	}
	else if (x >= flag && y < flag) {
		return flag * flag * 2 + recursive(n - 1, x - flag, y);
	}
	else {
		return flag * flag * 3 + recursive(n - 1, x - flag, y - flag);
	}
}

int main() {
	cin >> N >> R >> C;
	int result = recursive(N, R, C);
	cout << result << endl;



