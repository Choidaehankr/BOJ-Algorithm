#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	long long sum = 0;
	for (int i = 0; i < scoville.size(); i++) {
		q.push(scoville[i]);
		sum += scoville[i];
	}
	int cnt = 0, min_num = 0;
	while (q.size() >= 2) {
		int first = q.top();
		q.pop();
		int second = q.top();
		q.pop();
		q.push(first + (second * 2));
		sum = sum - (first + second) + (first + (second * 2));
		min_num = q.top();
		cnt++;
		if (min_num >= K) {
			break;
		}
	}
	if (min_num < K) {
		answer = -1;
	}
	else {
		answer = cnt;
	}
	return answer;
}
