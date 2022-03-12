#include <iostream>
#include <string>
#define MAX 999
using namespace std;
// S T A R T L I N K  .. A를 출력한 후 탐색 구간을 인덱스 3-8(R-K) 까지로 설정
// R T L I N K ... 중 가장 작은 I를 출력. 탐색 구간을 7-8(N-K)로 설정
// N K 중 모두 선택했다면, 다시 돌아와 남은 구간 (3-5)에서 문자를 골라 출력
bool check[101];
string str;

void solution(int start, int end) {
	int mini = MAX, idx = -1;
	for (int i = start; i < end + 1; i++) {
		if (!check[i] && mini > str[i]) {
			mini = str[i];
			idx = i;
		}
	}
	if (mini == MAX) return;
	check[idx] = true;
	for (int i = 0; str[i]; i++) {
		if (check[i])
			cout << str[i];
	}
	cout << '\n';
	solution(idx + 1, end);
	solution(start, idx - 1);
}

int main() {
	cin >> str;
	solution(0, str.size() - 1);
}