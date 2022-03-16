#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
int alpha[26];

// 문자열을 입력받고, 해당 문자열의 자릿수 (int len = str.size()) 를 파악한다.
// alpha 배열 인덱스 0-25를 A-Z로 매칭.
// 문자열이 ABCA일 경우, len = 4. A의 크기는 (10의 len-1제곱 + 10의 len-4제곱) = 1001, B의 크기는 10의 len-2제곱. C는 10의 len-3 제곱
// alpha[0]. 즉 A의 크기는 1001, alpha[1] = B = 100, alpha[2] = C = 10
// alpha를 내림 차순 정렬 후 9를 감소시켜가며 alpha[i]에 곱해준다.

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str; cin >> str;
		int len = str.size();
		int num = 1;
		for (int j = 0; j < str.size(); j++) {
			char c = str[j];
			alpha[c - 'A'] += pow(10, --len);
		}
	}
	sort(alpha, alpha + 26, [](int a, int b) {
		return a > b;
		});
	int x = 9;
	int sum = 0;
	for (int i = 0; i < 26; i++) {
		sum += alpha[i] * x--;
	}
	cout << sum << endl;
}