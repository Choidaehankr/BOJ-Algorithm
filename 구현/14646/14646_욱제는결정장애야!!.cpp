#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cnt = 0;  // 붙어있는 스티커의 개수
int sum = 0;  // 최종 결과
bool sticker[100001];  // false 
int main() {
	int N; cin >> N;
	for (int i = 0; i < 2*N; i++) {
		int num; cin >> num;
		if (sticker[num] == false) {  // 스티커가 없는 경우 true(스티커 있음)로 초기화
			cnt += 1;  // 현재 붙어있는 스티커의 개수를 증가
			sticker[num] = !sticker[num];
		}
		else {  // 이미 스티커가 붙어있는 경우
			cnt -= 1;  // 현재 붙어있는 스티커의 개수 감소
			// sticker[num] = !sticker[num]; 
		}
		sum = max(cnt, sum);  // 붙어있을 수 있는 스티커의 최대 개수를 구함
	}
	cout << sum << endl;
}