#include <iostream>
#include <algorithm>
using namespace std;

int testCase, L, N;
int main() {
	cin >> testCase;
	while (testCase--) {
		cin >> L >> N;
		int min_loc = 0, max_loc = 0;
		for (int i = 0; i < N; i++) {
			int num; 
			cin >> num;

			// 각 위치에서 막대 끝지점까지 가는데 걸리는 가장 짧은 시간
			int min_num = min(num, L - num);
			// 각 위치에서 막대 끝지점까지 가는데 걸리는 가장 긴 시간
			int max_num = max(num, L - num);

			// 각 위치의 개미가 떨어지는 시간 중 가장 큰 값 (마지막 개미가 떨어지는 시간)
			min_loc = max(min_loc, min_num);  
			max_loc = max(max_loc, max_num);
		}
		cout << min_loc << ' ' << max_loc << endl;
	}
}