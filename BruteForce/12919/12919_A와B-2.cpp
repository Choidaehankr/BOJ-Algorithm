#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 역으로 (dest -> src로 바꿀 수 있는지) 접근해야 시간초과가 안남.

void solution(string src, string dest) {
	if (src == dest) {
		cout << 1 << endl;
		exit(0);
	}
	if (src.size() > dest.size()) {
		return;
	}
	if (dest[dest.size() - 1] == 'A') {  // 마지막 문자가 A라면 해당 문자를 제거.
		string tmp = dest;
		tmp.erase(tmp.size() - 1);
		solution(src, tmp);
	}
	if (dest[0] == 'B') {  // 첫 문자가 B라면 뒤집고 마지막 문자를 제거.. 첫문자가 B라는 것은 두번째 연산 (B추가 후 뒤집기)를 실행했다는 뜻이므로
		string tmp = dest;
		reverse(tmp.begin(), tmp.end());
		tmp.erase(tmp.size() - 1);
		solution(src, tmp);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string S, T;
	cin >> S >> T;
	solution(S, T);
	cout << 0 << endl;
	return 0;
}