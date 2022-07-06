#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int gates[100001];

int main() {
	int G;  // Gate 수
	int P;  // Plane 수
	cin >> G >> P;
	int answer = 0;
	for (int i = 0; i < P; i++) {
		int num;
		cin >> num;
		bool flag = true;
		for (int j = num; j >= 1; j--) {
			if (gates[j] == 0) {
				gates[j] = i + 1;
				flag = false;
				answer++;
				break;
			}
		}
		if (flag == true) break;
	}		
	cout << answer;
}