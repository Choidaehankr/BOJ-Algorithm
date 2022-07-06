#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int gates[100001];
int answer = 0;

int find(int num) {
	if (num == gates[num]){
		return num;
	}
	else {
		return gates[num] = find(gates[num]);
	}
}

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
		int parent = find(num);  // num의 부모: 다음에 도킹할 게이트 번호
		if (parent != 0) {
			merge(parent, parent - 1);
			answer++;
		}
		else {  // 집합의 부모가 0 == 도킹할 게이트가 0 => 종료
			break;
		}
	}
	cout << answer;
}