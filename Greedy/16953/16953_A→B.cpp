#include <iostream>
#include <algorithm>
#define MAX 1000000000
using namespace std;

int cnt = 0;
long long int A;
int B;
int result = MAX;
void solution(long long int x, int cnt) {
	if (x == B) {  // 최소 탐색 횟수 갱신
		result = min(cnt, result);
	}
	if (x > B)  // x가 B보다 커지는 순간 B가 될 수 없으므로 return;
		return;
	solution(x * 2, cnt+1);  // 재귀를 통해 2를 곱하거나 뒤에 1을 더해줌
	solution(x * 10 + 1, cnt+1);
}

int main() {
	cin >> A >> B;
	solution(A, 1);
	if (result != MAX) {  // result 값이 갱신되었다면 A는 B가 될 수 있음.
		cout << result << endl;
	}
	else {
		cout << -1 << endl;
	}
}