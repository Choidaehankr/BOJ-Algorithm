#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> v;

int main() {
	cin >> N >> M;
	int cnt = 0, sum = 0;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
		if (num < 0) {  // 0으로부터 좌표가 음수에 존재하는 책을 나누기 위한 cnt
			cnt+=1;
		}
	}
	sort(v.begin(), v.end());
	// 음수
	for (int i = 0; i < cnt; i+= M) {  // M개를 들 수 있으므로 i+=M
		sum += abs(v[i] * 2);
	}
	// 양수
	for (int i = N - 1; i >= cnt; i -= M) {
		sum += v[i] * 2;
	}
	sum -= max(abs(v[0]), v[N-1]);  // 절대값이 가장 큰 좌표는 왕복이 필요 없으므로 빼준다.
	cout << sum << endl;
}