#include <iostream>
#include <vector>
using namespace std;

// 1을 발견한 인덱스 i, 
// i를 0으로 만들기 위해서 i+1을 누른다.
// i(왼쪽)는 이미 0이 되었기 때문에 i+1(가운데) 와 i+2 (오른쪽)을 ! 연산자로 상태 변경

vector<bool> v;
int N, cnt = 0;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		bool num; cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < N; i++) {
		if (v[i] == 1) {
			// v[i] = !v[i];  해도 그만, 안해도 그만
			v[i + 1] = !v[i + 1];
			v[i + 2] = !v[i + 2];
			cnt += 1;
		}
	}
	cout << cnt << endl;
}