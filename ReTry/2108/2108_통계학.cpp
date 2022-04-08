#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int minNum = 4000, maxNum = -4000;
double sum = 0, avg = 0;
int mfNum;  // 최빈값
vector<int> v;
map<int, int> m;

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		sum += num;  // 산술평균
		v.push_back(num);  // 중앙값
		m[num]++;
	}
	vector<pair<int, int>> res;
	for (auto it = m.begin(); it != m.end(); it++) {
		res.push_back(make_pair(it->first, it->second));
	}
	if (N != 1) {
		sort(res.begin(), res.end(), [](pair<int, int> a, pair<int, int> b) {
			if (a.second == b.second) {
				return a.first < b.first;
			}
			return a.second > b.second;
			});
		if (res[0].second == res[1].second) {
			mfNum = res[1].first;
		}
		else mfNum = res[0].first;
	}
	else {
		mfNum = v[0];
	}
	sort(v.begin(), v.end());
	avg = (sum / N) + 0.5;
	cout << floor(avg) << endl;  // 평균
	cout << v[N / 2] << endl;  // 중앙값
	cout << mfNum << endl;
	cout << abs(v[0] - v[N - 1]) << endl;  // 범위
}