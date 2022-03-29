#include <iostream>
using namespace std;

long long solution(long long num, long long exp, long long div) {
	if (exp == 0)
		return 1;
	long long tmpNum = solution(num, exp / 2, div);
	long long result = (tmpNum  * tmpNum) % div;
	if (exp & 1) {
		return (result * num) % div;
	}
	else {
		return result;
	}
}

int main() {
	long long num, exp, div;
	cin >> num >> exp >> div;
	cout << solution(num, exp, div) << endl;
}