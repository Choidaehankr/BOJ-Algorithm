#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// next_permutation 사용 
// next_permutation은 순열을 구하되, 내림차순으로 정렬. 이미 내림차순으로 정렬되어있다면 false를 반환.
// 2번째로 나오는 문자열을 구하면 된다.

int main() {
	int N; cin >> N;
	while (N--) {
		int cnt = 0;
		string str, tmp;
		cin >> str;
		while (1) {
			tmp = str;
			cnt++;
			if (cnt == 2 || !next_permutation(str.begin(), str.end())) {
				break;
			}
		}
		cout << tmp << endl;
	}
}