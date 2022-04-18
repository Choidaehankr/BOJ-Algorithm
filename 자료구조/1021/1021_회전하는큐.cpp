#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;

deque<int> dq;

int N, M, result = 0;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	for (int i = 0; i < M; i++) {
		int num, idx = 0;
		cin >> num;
		for (int j = 0; j < dq.size(); j++) {
			if (num == dq[j]) {
				idx = j;
				break;
			}
		}
		if (idx > dq.size() - idx) {
			while (1) {
				if (dq.front() == num) {
					dq.pop_front();
					break;
				} else{
					dq.push_front(dq.back());
					dq.pop_back();
					result++;
				}
			}
		}
		else {
			while (1) {
				if (dq.front() == num) {
					dq.pop_front();
					break;
				}
				else {
					dq.push_back(dq.front());
					dq.pop_front();
					result++;
				}
			}
		}
	}
	cout << result << endl;
}