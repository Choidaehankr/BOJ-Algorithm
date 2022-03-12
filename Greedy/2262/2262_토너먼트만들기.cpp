#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, sum=0;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	// 랭킹이 가장 낮은 (숫자가 큰) 사람 x를 찾고 양옆 사람 중 x와 차이가 가장 적은 숫자(랭킹)을 빼서 sub에 저장
	// 각 랭킹의 차 sub를 변수 sum에 누적시키고 x를 벡터에서 제거

	for (int i = 0; i < N; i++) {
		int idx, max_num=0, sub = 256;
		for (int j = 0; j < v.size(); j++) {  // 랭킹이 가장 낮은 사람 (가장 큰 수) 찾기
			if (v[j] > max_num) {
				max_num = v[j];
				idx = j;  
			}
		}
		if (v.size() == 1) {
			break;
		}
		if (idx == 0) {  // 인덱스가 0일 경우 오른쪽 사람을 봐야함.
			sub = abs(v[idx] - v[idx + 1]);
		}
		else if (idx == v.size() - 1) {  // 인덱스가 맨 끝일경우, 왼쪽 사람을 봐야함.
			sub = abs(v[idx - 1] - v[idx]);
		}
		else {
			for (int i = -1; i < 2; i += 2) {  // 위에 해당하지 않는다면 양 옆 중 자신과 차가 가장 작은 사람을 찾는다.
				sub = min(sub, abs(v[idx] - v[idx + i]));
			}
		}
		sum += sub;
		v.erase(v.begin()+idx);
	}
	cout << sum;
}