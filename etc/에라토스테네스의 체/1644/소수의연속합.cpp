#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define endl '\n'

using namespace std;

int n;

vector<int> v;
int answer = 0;
int primeNum[4000000];

void solution(int num) {
	for (int i = 0; i < v.size(); i++) {
		int sum = 0;
		for (int j = i; j < v.size(); j++) {
			sum += v[j];
			if (sum == num) {
				answer++;
				break;
			}
			if (sum > num) break;
		}
	}
	cout << answer << endl;
}

void getPrime(int num) {
	for (int i = 2; i <= num; i++) {
		primeNum[i] = i;
	}
	for (int i = 2; i <= sqrt(num); i++) {
		if (primeNum[i] == 0) {
			continue;
		}
		for (int j = i * i; j <= num; j += i) {
			primeNum[j] = 0;
		}
	}
	for (int i = 2; i <= num; i++) {
		if (primeNum[i] != 0)
			v.push_back(primeNum[i]);
	}
}

int main() {
	cin >> n;
	getPrime(n);
	solution(n);
}