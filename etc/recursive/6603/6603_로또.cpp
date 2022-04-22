#include <iostream>
#include <vector>
using namespace std;

int arr[13];
int lotto[6];
int k;

void solution(int s, int idx) {
	if (idx >= 6) {
		for (int i = 0; i < 6; i++) {
			cout << lotto[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = s; i < k; i++) {
		lotto[idx] = arr[i];
		solution(i + 1, idx + 1);
	}
}

int main() {
	while (1) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		solution(0, 0);
		cout << endl;
	}
}