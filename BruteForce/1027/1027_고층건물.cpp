#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 51
using namespace std;
double arr[MAX];
int leftBuildings[MAX];
int rightBuildings[MAX];
int N;

// 기울기를 이용해서 풀이한다.
// 기울기는 현재 빌딩과의 (높이 차이 / 떨어진 거리)

// 기울기 반환 함수
double getLean(double x, double y, double xHeight, double yHeight) {
	return double((yHeight - xHeight) / (y - x));
}

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	// 오른쪽 빌딩: 최대 기울기보다 커야한다.
	for (int i = 0; i < N; i++) {
		double maxLean = -1000000001;
		int cnt = 0;
		for (int j = i + 1; j < N; j++) {
			double lean = float(getLean(j, i, arr[j], arr[i]));
			if (lean > maxLean) {
				cnt++;
			}
			maxLean = max(maxLean, lean);
		}
		rightBuildings[i] = cnt;
	}
	// 왼쪽 빌딩: 최소 기울기보다 커지면 안된다.
	for (int i = N-1; i >= 0; i--) {
		double minLean = 1000000001;
		int cnt = 0;
		for (int j = i - 1; j >= 0; j--) {
			double lean = float(getLean(i, j, arr[i], arr[j]));
			if (lean < minLean) {
				cnt++;
			}
			minLean = min(minLean, lean);
		}
		leftBuildings[i] = cnt;
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		int sum = leftBuildings[i] + rightBuildings[i];
		result = max(sum, result);
	}
	cout << result << endl;
}