#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int gates[100001];
int answer = 0;

// num의 부모 찾기
int find(int num) {
	if (num == gates[num]){
		return num;
	}
	else {
		return gates[num] = find(gates[num]);
	}
}

// a의 부모를 b로 변경
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	gates[a] = b;
}

int main() {
	int G;  // Gate 수
	int P;  // Plane 수
	cin >> G >> P;
    
	for (int i = 1; i <= G; i++) {
		gates[i] = i;  // 부모를 자기 자신으로 초기화
	}

	int num;
	for (int i = 0; i < P; i++) {
		cin >> num;
		int parent = find(num);  
		if (parent != 0) {
			// 1 <= g1 <= G 이기 때문에 더 작은수와 merge 해줌
			// num의 부모 parent를 parent-1과 merge 함으로 다음에 num이 입력됐을 때, 도킹해야할 곳은 parent-1로 설정
			merge(parent, parent - 1);
			answer++;
		}
		else {  // 집합의 부모가 0 == 도킹할 게이트가 0 => 종료
			break;
		}
	}
	cout << answer;
}